----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/18/2026 12:50:30 PM
-- Design Name: 
-- Module Name: even_odd - Behavioral
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

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity even_odd is
    Port ( sensors : in STD_LOGIC_VECTOR (3 downto 0);
           even : out STD_LOGIC;
           odd : out STD_LOGIC);
end even_odd;

architecture Behavioral of even_odd is      
    begin
        with sensors select
            even <= '1' when "0011",
                    '1' when "0101",
                    '1' when "0110",
                    '1' when "1001",
                    '1' when "1010",
                    '1' when "1100",
                    '1' when "1111",
                    '0' when others;
        with sensors select
            odd <= '1' when "0001",
                   '1' when "0010",
                   '1' when "0100",
                   '1' when "0111",
                   '1' when "1000",
                   '1' when "1011",
                   '1' when "1110",
                   '1' when "1101",
                   '0' when others; 
end Behavioral;
