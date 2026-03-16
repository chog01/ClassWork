% EE4201 Lab 5: Frequency Response Sensitivity Analysis
clear; 

% Base Parameters
M_base = 1;      % Kg
fv_base = 5;     % N-s/m
K_base = 200;    % N/m

% Variations (-50% to +50% in 10% increments)
variations_pct = -50:10:50;
multipliers = 0.5:0.1:1.5;

% Arrays to store results for M variation
peak_gain_M = zeros(1, 11);
freq_peak_M = zeros(1, 11);
cutoff_freq_M = zeros(1, 11);
res_peak_M = zeros(1, 11);
M_values = multipliers * M_base;

% Arrays to store results for fv variation
peak_gain_fv = zeros(1, 11);
freq_peak_fv = zeros(1, 11);
cutoff_freq_fv = zeros(1, 11);
res_peak_fv = zeros(1, 11);
fv_values = multipliers * fv_base;

% Arrays to store results for K variation
peak_gain_K = zeros(1, 11);
freq_peak_K = zeros(1, 11);
cutoff_freq_K = zeros(1, 11);
res_peak_K = zeros(1, 11);
K_values = multipliers * K_base;

% --- 1. Varying M ---
for i = 1:length(multipliers)
    M = M_values(i);
    % Create transfer function for updated M
    sys = tf([1/M], [1, fv_base/M, K_base/M]);
    
    % Get peak gain (absolute) and bandwidth
    [peak_mag, f_peak] = getPeakGain(sys);
    dc_mag = dcgain(sys);
    
    % Convert to dB and find resonant peak difference
    peak_gain_M(i) = 20*log10(peak_mag);
    res_peak_M(i) = 20*log10(peak_mag) - 20*log10(dc_mag);
    freq_peak_M(i) = f_peak;
    cutoff_freq_M(i) = bandwidth(sys);
end

% --- 2. Varying fv ---
for i = 1:length(multipliers)
    fv = fv_values(i);
    % Create transfer function for updated fv
    sys = tf([1/M_base], [1, fv/M_base, K_base/M_base]);
    
    [peak_mag, f_peak] = getPeakGain(sys);
    dc_mag = dcgain(sys);
    
    peak_gain_fv(i) = 20*log10(peak_mag);
    res_peak_fv(i) = 20*log10(peak_mag) - 20*log10(dc_mag);
    freq_peak_fv(i) = f_peak;
    cutoff_freq_fv(i) = bandwidth(sys);
end

% --- 3. Varying K ---
for i = 1:length(multipliers)
    K = K_values(i);
    % Create transfer function for updated K
    sys = tf([1/M_base], [1, fv_base/M_base, K/M_base]);
    
    [peak_mag, f_peak] = getPeakGain(sys);
    dc_mag = dcgain(sys);
    
    peak_gain_K(i) = 20*log10(peak_mag);
    res_peak_K(i) = 20*log10(peak_mag) - 20*log10(dc_mag);
    freq_peak_K(i) = f_peak;
    cutoff_freq_K(i) = bandwidth(sys);
end

% --- Plotting Question 1: Resonant Peak vs % Variation---
figure(1);
plot(variations_pct, res_peak_M, '-o', 'LineWidth', 1.5, 'DisplayName', 'M Variation');
hold on;
plot(variations_pct, res_peak_fv, '-o', 'LineWidth', 1.5, 'DisplayName', 'fv Variation');
plot(variations_pct, res_peak_K, '--^', 'LineWidth', 1.5, 'DisplayName', 'K Variation');
hold off;
title('Question 1: Resonant Peak Sensitivity');
xlabel('Parameter % Variation (-50 to 50%)');
ylabel('Resonant Peak (dB)');
legend('show', 'Location', 'best');
grid on;

% --- Plotting Question 2: Cut-Off Frequency vs Parameter Values ---
figure(2);
sgtitle('Question 2: Cut-Off Frequency Parameter Sensitivity');

subplot(3,1,1);
plot(M_values, cutoff_freq_M, '-o', 'LineWidth', 1.5);
title('Cut-Off Freq vs M');
xlabel('M (Kg)');
ylabel('Bandwidth (rad/s)');
grid on;

subplot(3,1,3);
plot(fv_values, cutoff_freq_fv, '-o', 'LineWidth', 1.5);
title('Cut-Off Freq vs fv');
xlabel('fv (N-s/m)');
ylabel('Bandwidth (rad/s)');
grid on;

subplot(3,1,2);
plot(K_values, cutoff_freq_K, '-o', 'LineWidth', 1.5);
title('Cut-Off Freq vs K');
xlabel('K (N/m)');
ylabel('Bandwidth (rad/s)');
grid on;


