library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity even_odd_tb is
--no entity
end even_odd_tb;

architecture Behavioral of even_odd_tb is

    -- Component Declaration for the Unit Under Test (UUT)
    component even_odd
    Port ( sensors : in STD_LOGIC_VECTOR (3 downto 0);
           even : out STD_LOGIC;
           odd : out STD_LOGIC);
    end component;

    -- Inputs
      signal sensors: std_logic_vector (3 downto 0);
    -- Outputs
      signal even: std_logic;
      signal odd: std_logic;

begin

    uut: even_odd PORT MAP (
          sensors => sensors,
          even => even,
          odd => odd
    );

    -- Stimulus process
    stim_proc: process
    begin
        wait for 100 ns;
        
        -- Case 0: sensors = "0000"  even = '0' odd = '0'
        sensors <= "0000"; wait for 10 ns;
        -- Case 1: sensors = "0001"  even = '0' odd = '1'
        sensors <= "0001"; wait for 10 ns;
        -- Case 2: sensors = "0010"  even = '0' odd = '1'
        sensors <= "0010"; wait for 10 ns;
        -- Case 3: sensors = "0011"  even = '1' odd = '0'
        sensors <= "0011"; wait for 10 ns;
        -- Case 4: sensors = "0100"  even = '0' odd = '1'
        sensors <= "0100"; wait for 10 ns;
        -- Case 5: sensors = "0101"  even = '1' odd = '0'
        sensors <= "0101"; wait for 10 ns;
        -- Case 6: sensors = "0110"  even = '1' odd = '0'
        sensors <= "0110"; wait for 10 ns;
        -- Case 7: sensors = "0111"  even = '0' odd = '1'
        sensors <= "0111"; wait for 10 ns;
        -- Case 8: sensors = "1000"  even = '0' odd = '1'
        sensors <= "1000"; wait for 10 ns;
        -- Case 9: sensors = "1001"  even = '1' odd = '0'
        sensors <= "1001"; wait for 10 ns;
        -- Case 10: sensors = "1010"  even = '1' odd = '0'
        sensors <= "1010"; wait for 10 ns;
        -- Case 11: sensors = "1011"  even = '0' odd = '1'
        sensors <= "1011"; wait for 10 ns;
        -- Case 12: sensors = "1100"  even = '1' odd = '0'
        sensors <= "1100"; wait for 10 ns;
        -- Case 13: sensors = "1101"  even = '0' odd = '1'
        sensors <= "1101"; wait for 10 ns;
        -- Case 14: sensors = "1110"  even = '0' odd = '1'
        sensors <= "1110"; wait for 10 ns;
        -- Case 15: sensors = "1111"  even = '1' odd = '0'
        sensors <= "1111"; wait for 10 ns;
        wait;
    end process;

end Behavioral;