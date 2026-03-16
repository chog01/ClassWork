library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity referee_decision is
    Port ( 
        head_ref : in STD_LOGIC; -- The Head Referee (Tie Breaker)
        ref1     : in STD_LOGIC;
        ref2     : in STD_LOGIC;
        ref3     : in STD_LOGIC;
        decision : out STD_LOGIC -- Final Decision Output
    );
end referee_decision;

architecture dataflow of referee_decision is
begin
    -- Dataflow modeling using the derived boolean equation
    -- Output is HIGH if Head Ref supports AND at least one other supports
    -- OR if all three regular refs support (overriding a LOW Head Ref).
    
    decision <= (head_ref and (ref1 or ref2 or ref3)) or 
                (ref1 and ref2 and ref3);

end dataflow;