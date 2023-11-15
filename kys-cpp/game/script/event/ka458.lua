if CheckRoleMorality(0, 50, 100) == false then goto label0 end;
    Talk("最近江湖上對你的風評還挺不錯的，希望你繼續保持下去.", 68, 0);
::label0::
    exit();
    Talk("你這作惡多端的小子，老天也饒不了你．", 68, 0);
    ModifyEvent(-2, -2, -2, -2, 459, -1, -1, -2, -2, -2, -2, -2, -2);
exit();
