clear;
% Definitions
r1 = 10e3;
r2 = 30e3;
r3 = 60e3;
c = 2e-6;
Vs = 12;

%open switch
Rth_op = (r2+r1)*r3/(r1+r2+r3);
Vth_op = r3*Vs/(r1+r2+r3);

%closed switch 
Rth_cl = (r3*r2)/(r3+r2);
Vth_cl = Vs*r3/(r3+r2);

% Solving the open switch
tao_op = Rth_op*c;
Vo = 0;

t = 0:0.01:2;
for i=1:201
    v(i) = Vth_op + (Vo - Vth_op)*exp(-t(i)/tao_op);
end

%Solving the closed switch
tao_cl = Rth_cl*c;
Vo = 7.2;

tc = 1:0.01:2;
for i=1:length(tc)
    vc(i) = Vth_cl + (Vo - Vth_cl)*exp(-(tc(i)-1)/tao_cl);
end
plot(t,v,'r--'); % Top plot
hold on;
plot(tc,vc,'b'); % Bottom plot
hold off;
