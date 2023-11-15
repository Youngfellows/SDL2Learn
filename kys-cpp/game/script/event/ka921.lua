ModifyEvent(-2, -2, -2, -2, -1, -1, -1, 3500, 3500, 3500, -2, -2, -2);
AddItem(127, 1);
AddItem(186, 2);
AddItem(86, 1);
if InTeam(61) == false then goto label0 end;
    Talk("克兒，出門在外要小心。", 60, 0);
    Talk("知道了，師父。", 61, 1);
    Talk("〈是歐陽鋒。這西毒果然厲害，來去我竟然絲毫未察覺。〉", 0, 5);
exit();
::label0::
    Talk("去死吧！", 60, 0);
    Talk("啊，是歐陽鋒回來了！", 0, 1);
    if TryBattle(147) == true then goto label1 end;
        Dead();
        exit();
::label1::
        LightScence();
        Talk("好厲害的西毒，在我背後都沒察覺。", 0, 0);
exit();
