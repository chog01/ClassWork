----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/04/2026 01:05:57 PM
-- Design Name: 
-- Module Name: 8_BIT_REGISTER - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

entity EIGHT_BIT_REGISTER is
    Port ( data_In : in STD_LOGIC_VECTOR (7 downto 0);
           loadEn : in STD_LOGIC;
           clearEn : in STD_LOGIC;
           clearMode : in STD_LOGIC;
           clock : in STD_LOGIC;
           data_Out : out STD_LOGIC_VECTOR (7 downto 0));
end EIGHT_BIT_REGISTER;

architecture Behavioral of EIGHT_BIT_REGISTER is
    constant ACTIVE: std_logic := '1';
    constant notACTIVE: std_logic := '0';
    
    signal reg_data : std_logic_vector(7 downto 0) := (others => '0');
begin
data_Out <= reg_data;
    process(clock)

    begin
    if(rising_edge(clock)) then
        if (clearEn = ACTIVE) then
            if (clearMode = ACTIVE) then
                reg_data <= "0000" & reg_data(3 downto 0);
            elsif (clearMode = notACTIVE) then
                reg_data <= reg_data(7 downto 4) & "0000";
            end if;
        elsif (loadEn = ACTIVE) then
            reg_data <= data_In;
        end if;
    end if;
        
    end process;

end Behavioral;
