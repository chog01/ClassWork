library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL; -- Useful for iterating if you wanted a loop, but hardcoding is clear here.

entity Referee_Decision_tb is
-- Testbench has no ports
end Referee_Decision_tb;

architecture Behavioral of Referee_Decision_tb is

    -- Component Declaration for the Unit Under Test (UUT)
    component Referee_Decision
    Port ( 
        ref1     : in  STD_LOGIC;
        ref2     : in  STD_LOGIC;
        ref3     : in  STD_LOGIC;
        head_ref : in  STD_LOGIC;
        decision : out STD_LOGIC
    );
    end component;

    -- Inputs
    signal ref1     : std_logic := '0';
    signal ref2     : std_logic := '0';
    signal ref3     : std_logic := '0';
    signal head_ref : std_logic := '0';

    -- Outputs
    signal decision : std_logic;

begin

    -- Instantiate the Unit Under Test (UUT)
    uut: Referee_Decision PORT MAP (
          ref1 => ref1,
          ref2 => ref2,
          ref3 => ref3,
          head_ref => head_ref,
          decision => decision
    );

    -- Stimulus process
    stim_proc: process
    begin
        -- Hold reset state for 100 ns.
        wait for 100 ns;

        -- Test all 16 combinations
        -- Format: ref1, ref2, ref3, head_ref
        
        -- Case 0: 0000 -> 0
        ref1 <= '0'; ref2 <= '0'; ref3 <= '0'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 1: 0001 -> 1 (Head Ref alone is not enough, wait. 1 vote total = Low)
        -- Correction: Head Ref is a vote. 0001 = 1 vote. Result: LOW.
        ref1 <= '0'; ref2 <= '0'; ref3 <= '0'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 2: 0010 -> 0
        ref1 <= '0'; ref2 <= '0'; ref3 <= '1'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 3: 0011 -> 1 (Tie 2-2? No, Ref3+Head = 2 votes. Tie! Head is 1, so HIGH)
        ref1 <= '0'; ref2 <= '0'; ref3 <= '1'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 4: 0100 -> 0
        ref1 <= '0'; ref2 <= '1'; ref3 <= '0'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 5: 0101 -> 1 (Tie 2-2, Head is 1 -> HIGH)
        ref1 <= '0'; ref2 <= '1'; ref3 <= '0'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 6: 0110 -> 0 (Tie 2-2, Head is 0 -> LOW)
        ref1 <= '0'; ref2 <= '1'; ref3 <= '1'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 7: 0111 -> 1 (Majority 3-1 -> HIGH)
        ref1 <= '0'; ref2 <= '1'; ref3 <= '1'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 8: 1000 -> 0
        ref1 <= '1'; ref2 <= '0'; ref3 <= '0'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 9: 1001 -> 1 (Tie 2-2, Head is 1 -> HIGH)
        ref1 <= '1'; ref2 <= '0'; ref3 <= '0'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 10: 1010 -> 0 (Tie 2-2, Head is 0 -> LOW)
        ref1 <= '1'; ref2 <= '0'; ref3 <= '1'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 11: 1011 -> 1 (Majority 3-1 -> HIGH)
        ref1 <= '1'; ref2 <= '0'; ref3 <= '1'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 12: 1100 -> 0 (Tie 2-2, Head is 0 -> LOW)
        ref1 <= '1'; ref2 <= '1'; ref3 <= '0'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 13: 1101 -> 1 (Majority 3-1 -> HIGH)
        ref1 <= '1'; ref2 <= '1'; ref3 <= '0'; head_ref <= '1'; wait for 10 ns;
        
        -- Case 14: 1110 -> 1 (Majority 3-1 -> HIGH - Override Head)
        ref1 <= '1'; ref2 <= '1'; ref3 <= '1'; head_ref <= '0'; wait for 10 ns;
        
        -- Case 15: 1111 -> 1 (Unanimous -> HIGH)
        ref1 <= '1'; ref2 <= '1'; ref3 <= '1'; head_ref <= '1'; wait for 10 ns;

        wait;
    end process;

end Behavioral;