----------------------------------------------------------------------------------
-- Company:CPE 3020
-- Engineer: Noah Marchman
-- 
-- Create Date: 02/24/2026 09:10:58 AM
-- Design Name: wrapper
-- Module Name: wrapper - Behavioral
-- Project Name: Led Control
-- Target Devices: Basys 3
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity wrapper is
    Port ( switch : in STD_LOGIC_VECTOR (15 downto 0);
           btnL : in STD_LOGIC;
           btnR : in STD_LOGIC;
           LEDs : out STD_LOGIC_VECTOR (15 downto 0);
           s_seg : out STD_LOGIC_VECTOR (6 downto 0);
           s_sel : out STD_LOGIC_VECTOR (3 downto 0));
end wrapper;

architecture Behavioral of wrapper is
    
    --Component declaration
    component led_control is
        Port(
            switch : in std_logic_vector(2 downto 0); --we only use the right 3 switches
            btnL   : in std_logic;
            btnR   : in std_logic;
            LEDs   : out std_logic_vector(15 downto 0);
            s_seg  : out std_logic_vector(6 downto 0);
            s_sel  : out std_logic_vector(3 downto 0)
            );
    end component;
begin
    --Initiate the design module
    U1: led_control port map(
        switch => switch(2 downto 0),
        btnL => btnL,
        btnR => btnR,
        LEDs => LEDs,
        s_seg => s_seg,
        s_sel => s_sel
    );

end Behavioral;
