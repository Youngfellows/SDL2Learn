CheckSubMapPic(80, 1, 6068, 0, 21);
    Talk("楊兄，請你先回神鵰穴中，若有需要你幫忙時，我再去找你．", 0, 1);
    LeaveTeam(58);
    ModifyEvent(7, 6, 1, 1, 1091, -1, -1, 6186, 6186, 6186, 0, -2, -2);
    exit();
::label0::
    Talk("楊兄，請你先回古墓，若有需要你幫忙時，我再去找你．", 0, 1);
    LeaveTeam(58);
    ModifyEvent(18, 0, 1, 1, 1091, -1, -1, 6188, 6188, 6188, 0, -2, -2);
    SetSubMapLayerData(18, 1, 44, 31, 0);
    SetSubMapLayerData(18, 1, 44, 30, 0);
exit();
