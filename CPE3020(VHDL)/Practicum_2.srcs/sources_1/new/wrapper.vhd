----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 03/04/2026 01:52:20 PM
-- Design Name: 
-- Module Name: wrapper - Behavioral
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

entity wrapper is
    Port ( data_In   : in STD_LOGIC_VECTOR (7 downto 0);
           loadEn    : in STD_LOGIC;
           clearEn   : in STD_LOGIC;
           clearMode : in STD_LOGIC;
           clock     : in std_logic;
           data_out  : out STD_LOGIC_VECTOR (7 downto 0));
end wrapper;

architecture Behavioral of wrapper is
    
    --Component declaration
    component EIGHT_BIT_REGISTER is
        Port(
            data_In   : in std_logic_vector(7 downto 0);
            loadEn    : in std_logic;
            clearEn   : in std_logic;
            clearMode : in std_logic;
            clock     : in std_logic;
            data_Out  : out std_logic_vector(7 downto 0)
            );
    end component;
begin
    --Initiate the design module
    U1: EIGHT_BIT_REGISTER port map(
        data_in => data_in(7 downto 0),
        loadEn => loadEn,
        clearEn => clearEn,
        clearMode => clearMode,
        clock => clock,
        data_Out => data_Out(7 downto 0)
    );

end Behavioral;
