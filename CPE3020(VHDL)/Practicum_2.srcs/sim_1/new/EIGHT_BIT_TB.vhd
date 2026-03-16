library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity EIGHT_BIT_REGISTER_tb is
-- Testbenches have no ports!
end EIGHT_BIT_REGISTER_tb;

architecture Behavioral of EIGHT_BIT_REGISTER_tb is

    -- COMPONENT DECLARATION DELETED. We will use direct instantiation below.

    signal clock      : std_logic := '0';
    signal data_In    : std_logic_vector(7 downto 0) := (others => '0');
    signal loadEn     : std_logic := '0';
    signal clearEn    : std_logic := '0';
    signal clearMode  : std_logic := '0';
    signal data_Out   : std_logic_vector(7 downto 0);

    constant clk_period : time := 10 ns;

begin

    -- DIRECT INSTANTIATION: Notice "entity work."
    -- This guarantees the simulator finds your exact, updated main code.
    uut: entity work.EIGHT_BIT_REGISTER port map (
          data_In   => data_In,
          loadEn    => loadEn,
          clearEn   => clearEn,
          clearMode => clearMode,
          clock     => clock,
          data_Out  => data_Out
        );

    -- Clock generation
    clk_process : process
    begin
        clock <= '0';
        wait for clk_period/2;
        clock <= '1';
        wait for clk_period/2;
    end process;

    -- Stimulus process
    stim_proc: process
    begin        
        -- Wait for global reset
        wait for 20 ns;

        -- Test 1: Load the register with all 1s (0xFF)
        data_In <= "11111111";
        loadEn <= '1';
        wait for clk_period;
        loadEn <= '0';
        
        -- Test 2: Clear mode 1 (Should clear TOP 4 bits: 0000 1111)
        clearMode <= '1';
        clearEn  <= '1';
        wait for clk_period;
        clearEn  <= '0';
        
        -- Test 3: Reload everything (1010 1010)
        data_In <= "10101010";
        loadEn <= '1';
        wait for clk_period;
        loadEn <= '0';
        
        -- Test 4: Clear mode 0 (Should clear BOTTOM 4 bits: 1010 0000)
        clearMode <= '0';
        clearEn  <= '1';
        wait for clk_period;
        clearEn  <= '0';

        wait; -- Stop the simulation here
    end process;

end Behavioral;