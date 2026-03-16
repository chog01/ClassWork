----------------------------------------------------------------------------------
-- Company:CPE 3020
-- Engineer: Noah Marchman
-- 
-- Create Date: 02/24/2026 09:10:58 AM
-- Design Name: Lab_2 
-- Module Name: led_control_ - Behavioral
-- Project Name: Led Control
-- Target Devices: Basys 3
 ----------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.numeric_std.ALL;

entity Lab_2_tb is
--Test benches have no ports.
end Lab_2_tb;


architecture Behavioral of Lab_2_tb is

    -- Component declaraton for UUT
    component led_control
        Port (
            switch : in std_logic_vector(2 downto 0);
            btnL   : in std_logic;
            btnR   : in std_logic;
            LEDs   : out std_logic_vector(15 downto 0);
            s_seg  : out std_logic_vector(6 downto 0);
            s_sel  : out std_logic_vector(3 downto 0)
        );
    end component;
    
    --Signal declaraton
    signal switch : std_logic_vector(2 downto 0) := "000";
    signal btnL   : std_logic := '0';
    signal btnR   : std_logic := '0';
    signal LEDs   : std_logic_vector(15 downto 0);
    signal s_seg  : std_logic_vector(6 downto 0);
    signal s_sel  : std_logic_vector(3 downto 0);

begin

    --Initalize the UUT
    uut: led_control PORT MAP(
        switch => switch,
        btnL => btnl,
        btnR => btnR,
        LEDs => LEDs,
        s_seg => s_seg,
        s_sel => s_sel
       );

    --Stimulus process
    stim_proc: process
    begin
        --Loop through all possible conditions.
        for i in 0 to 7 loop
            switch <= std_logic_vector(TO_UNSIGNED(i,3));
            
            --Case 1: No Buttons Pressed
            btnL <= '0'; btnR <= '0';
            wait for 25ns;
            
            --Case 2: Only Left Button
            btnL <= '1'; btnR <= '0';
            wait for 25ns;
            
            --Case 3: Only Right Button 
            btnL <= '0'; btnR <= '1';
            wait for 25ns;
            
            --Case 4: Both Buttons
            btnL <= '1'; btnr <= '1';
            wait for 25ns;
        end loop;
        wait for 200ns;
    end process;
            
end Behavioral;
