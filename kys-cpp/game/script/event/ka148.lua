if InTeam(9) == true then goto label0 end;
    Talk("張無忌，記得你的承諾，事後來到萬安寺找我，實踐你答應我要替我做的三件事。", 0, 1);
    Talk("太師父!有了這黑玉斷續膏，俞師伯的傷就有的救了。", 194, 0);
    exit();
::label0::
    Talk("本門的續骨妙藥秘密之極，連本門尋常弟子也不知其名，這小子卻從何處聽來？", 9, 5);
    Talk("趙姑娘，在下依約前來，不知姑娘有何吩咐。", 194, 0);
    Talk("你來做什麼？我是叫張無忌來找我，不是你，滾。", 9, 5);
    if InTeam(114) == false then goto label1 end;
        Talk("好，第一件事情很簡單，你一定做得到 ，那就是你闖蕩江湖時把我帶在身邊，這麼簡單的事情應該做得到吧!", 194, 0);
        Talk("這．．．好，我答應你就是，還有呢?", 9, 5);
        Talk("好，第一件事情很簡單，你一定做得到 ，那就是你闖蕩江湖時要把我帶在身邊，這麼簡單的事情應該做得到吧!", 145, 1);
::label1::
        if InTeam(49) == false then goto label2 end;
            Talk("你．．．好．．．我答應。", 49, 5);
            Talk("公子．．．", 0, 1);
::label2::
            Talk("還有你的侍女小昭，以後你可不準娶她，這樣既沒有違反你所謂的正道，也沒有叫你做啥不義之事。", 194, 0);
            if AskJoin () == true then goto label3 end;
                Talk("暫時就這樣，剩下的事等我想到在跟你說，嘻嘻", 194, 0);
                exit();
::label3::
                if TeamIsFull() == false then goto label4 end;
                    Talk("你的隊伍已滿，我無法加入．", 194, 0);
                    exit();
::label4::
                    Talk("無忌兄弟，你放心，小昭我會好好照顧的，你也知道我的為人，我平常就熱心助人．．．", 0, 1);
                    DarkScence();
                    ModifyEvent(-2, -2, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
                    LightScence();
                    Join(39);
exit();
