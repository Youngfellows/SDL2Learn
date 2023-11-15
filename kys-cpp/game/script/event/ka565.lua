Talk("阿彌陀佛！阿門！好兄弟，你可別怪我挖你的墓．我是為了過關才如此做的，逼不得已．", 0, 1);
if InTeam(49) == true then goto label0 end;
    exit();
::label0::
    Talk("干，真是沒品，挖人墳墓", 49, 0);
    AddMorality(-5);
exit();
