----------------------------------------------------------------------------------
-- Company:CPE 3020
-- Engineer: Noah Marchman
-- 
-- Create Date: 02/24/2026 09:10:58 AM
-- Design Name: Lab_2 
-- Module Name: led_control - Behavioral
-- Project Name: Led Control
-- Target Devices: Basys 3
----------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity led_control is
    Port (
        switch : in std_logic_vector(2 downto 0);   -- Right 3 slide switches
        btnL   : in std_logic;                      -- Left button
        btnR   : in std_logic;                      -- Right button
        LEDs   : out std_logic_vector(15 downto 0); -- 16 LEDs on the board
        s_seg  : out std_logic_vector(6 downto 0);  -- Seven segment display segments
        s_sel  : out std_logic_vector(3 downto 0)   -- Anode to select display digit
    );
end led_control;

architecture Behavioral of led_control is
begin

    --Seven Segement Decoder
    process(switch)
    begin
    case switch is
        when "000" =>s_seg<= "1000000"; -- 0
        when "001" =>s_seg<= "1111001"; -- 1
        when "010" =>s_seg<= "0100100"; -- 2
        when "011" =>s_seg<= "0110000"; -- 3
        when "100" =>s_seg<= "0011001"; -- 4
        when "101" =>s_seg<= "0010010"; -- 5
        when "110" =>s_seg<= "0000010"; -- 6
        when "111" =>s_seg<= "1111000"; -- 7
        when others =>s_seg<= "1111111";
        end case;
    end process;
    
s_sel <= "1110"; -- Anode Control: Only the right digit should be on

    -- LED Logic
    process(switch,btnL,btnR)
        variable led_logic : std_logic_vector(15 downto 0);
        variable num       : integer range 0 to 7;
    begin
        led_logic := (others=>'0'); -- Turning all LEDs off by default.
        num   := to_integer(unsigned(switch)); -- assigning the number of switches to num variable.
        
        -- Left LED Logic starting from led 15
        if btnL = '1' then -- If the left button is pressed run the loop.
            for i in 0 to 7 loop -- run the loop 7 times.
                if i < num then -- this controls when the loop stops based on the number of switches.
                    led_logic(15 - i) := '1'; -- Since we are starting from the left led then we need to start at 15 and work our way down.
                end if;
            end loop;
        end if;
        
        -- Right LED logic starting from led 0
        -- Same as left but for the right button
            if btnR = '1' then
            for i in 0 to 7 loop
                if i < num then
                    led_logic(i) := '1'; --The right leds start at 0 and work their way up.
                end if;
            end loop;
        end if;     
        
        LEDs <= led_logic; -- Apply pattern to output
    end process;
    
end Behavioral;
     