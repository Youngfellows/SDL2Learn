if HaveItemBool(153) == true then goto label0 end;
    exit();
::label0::
    AddItemWithoutHint(153, -1);
    ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 4664, 4664, 4664, -2, -2, -2);
    if Check14BooksPlaced() == true then goto label1 end;
        exit();
::label1::
        PlayWave(23);
        Talk("咦！好像有什麼聲音．", 0, 1);
        DarkScence();
        SetSubMapLayerData(-2, 1, 18, 25, 0);
        SetSubMapLayerData(-2, 1, 18, 26, 0);
        LightScence();
exit();
