if isUsingItem(186) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(186, -1);
    Talk("什麼!你說要跟我走，真的嗎?我說的是那種我帶走你，然後做我老婆那種．", 116, 0);
    Add3EventNum(-2, 1, 0, 1, -1)
exit();
