if InTeam(29) == true then goto label0 end;
    exit();
::label0::
    Talk("田兄好刀法，令狐沖也很佩服，有空上華山來比劃比劃．", 29, 0);
    ModifyEvent(-2, 3, 1, 1, 200, 238, -1, 7624, 7624, 7624, -2, -2, -2);
    ModifyEvent(-2, -2, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2);
    WalkFromTo(48, 36, 17, 37);
    Talk("大師兄被師父處罰到思過崖去面壁了．", 35, 0);
    Talk("令狐兄，我老田上華山來找你喝酒拉．", 29, 0);
    Talk("看到他們精妙的招式，讓我受益良多．", 35, 0);
    ModifyEvent(58, 0, -2, -2, 182, -2, -2, -2, -2, -2, -2, -2, -2);
    ModifyEvent(58, 20, -2, -2, 182, -2, -2, -2, -2, -2, -2, -2, -2);
exit();