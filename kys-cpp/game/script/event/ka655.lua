if CheckRoleAttack(0, 90, 1000) == true then goto label0 end;
    Talk("我看這塊巨石門大有問題，後面肯定藏有寶物．", 0, 1);
    exit();
::label0::
    if HaveItemBool(106) == true then goto label1 end;
        Talk("我看這塊巨石門大有問題，後面肯定藏有寶物．", 0, 1);
        exit();
        if HaveItemBool(109) == true then goto label2 end;
            Talk("我看這塊巨石門大有問題，後面肯定藏有寶物．", 0, 1);
            exit();
            if HaveItemBool(117) == true then goto label3 end;
                Talk("我看這塊巨石門大有問題，後面肯定藏有寶物．", 0, 1);
                exit();
::label1::
::label2::
::label3::
                Talk("看我的！", 0, 1);
                BreakStoneGate();
                ModifyEvent(-2, 2, 1, 1, -1, -1, -1, 7746, 7746, 7746, -2, -2, -2);
                ModifyEvent(-2, 3, 0, 0, -1, -1, -1, 7804, 7804, 7804, -2, -2, -2);
                ModifyEvent(-2, 4, 1, 1, -1, -1, -1, 7862, 7862, 7862, -2, -2, -2);
exit();
