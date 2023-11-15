if InTeam(9) == true then goto label0 end;
    Talk("何掌門趕快離開吧。", 6, 0);
    exit();
::label0::
    Talk("趕快離開這里吧。", 6, 0);
    Talk("殷六俠趕快離開這吧。", 9, 0);
    Talk("滾，我們峨嵋派不需要魔教妖人來救我。", 6, 0);
    PlayAnimation(16, 5468, 5496);
    DarkScence();
    ModifyEvent(-2, 16, 1, -2, 1195, -1, -1, 5238, 5238, 5238, -2, -2, -2);
    ModifyEvent(-2, 19, 1, -2, 1196, -2, -2, -2, -2, -2, -2, -2, -2);
    LightScence();
    Talk("你便是武當張翠山之子張無忌?", 122, 0);
exit();
