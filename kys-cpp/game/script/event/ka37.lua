if HaveItemBool(173) == false then goto label0 end;
    ModifyEvent(-2, -2, -2, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2);
    exit();
::label0::
    Talk("什麼味道這樣香濃，我頭好昏，啊！難道這紅樹叢有毒 ．．．．．．", 0, 1);
    PlayAnimation(-1, 5974, 5992);
    DarkScence();
    OldSetScencePosition(30, 49);
    LightScence();
    PlayAnimation(-1, 6014, 6024);
    Talk("咦！這是那里？莫非我已昏厥多時？此處非平常之地．", 0, 1);
    ModifyEvent(-2, -2, -2, -2, -2, -2, 38, -2, -2, -2, -2, -2, -2);
exit();
