Talk("唉！阿彌陀佛．少俠為了奪書，做下此等惡事，已誤入邪途了．", 70, 0);
if HaveItemBool(74) == true then goto label0 end;
    exit();
::label0::
    Talk("稟報方丈，喬峰那惡賊上山來了。", 96, 1);
    Talk("小師傅不必稟報了，喬某已經到了。", 50, 0);
    Talk("不知喬施主今日到此，有何指教？", 70, 1);
    Talk("喬某今日不請自來，只為找人。在下的一位朋友被丁春秋所擒，聽說丁老怪上了少室山，故而喬某才不得以上山打擾。", 50, 0);
    Talk("方丈，你千萬別聽這惡賊胡說。我看到他害了死了自己的恩師玄苦，此次上山必有圖謀。", 96, 1);
    Talk("姐夫……救我……", 130, 0);
    Talk("阿紫！星宿老怪，你快放了阿紫！", 50, 1);
    Talk("喬兄，你是契丹英雄，但你未免太不把我中原群雄放在眼里了。慕容復不才，今日想領教你的高招。", 139, 1);
    Talk("素聞公子英名，今日得見高賢，大慰平生。", 50, 0);
    Talk("慕容公子，你既與我大哥齊名，此刻怎可乘人之危，豈不貽笑天下？", 138, 1);
    Talk("兄弟，原來你也在這里。", 50, 0);
    Talk("姓喬的，老父看你年輕，本想讓你幾招。既然你自己找死，就休要怨我了！", 46, 1);
    Talk("喬峰，姓莊的今天也要和你把殺父之仇算一算。", 48, 0);
    Talk("傳令下去，少林僧眾守住四方不能讓喬峰逃走，必要留下喬鋒查清玄苦的死因。", 70, 1);
    Talk("慕容公子，姓莊的，丁老怪，你們便三位齊上，我喬峰何懼？！拿酒來！兄弟，你我生死與共，不枉了結義一場。死也罷，活也罷，大家痛痛快快地再喝他一場。", 50, 0);
    Talk("正要跟大哥喝一場！", 138, 1);
    Talk("大哥，三弟，你們喝酒怎么不來叫我？", 49, 0);
    Talk("大哥，這也是我的結義哥哥虛竹。二哥，來拜見大哥！", 138, 1);
    Talk("兄弟，喬某能結交你這等英雄，喜歡得緊。", 50, 0);
    Talk("喬幫主！", 0, 1);
    Talk("原來是你。怎么，閣下也想一起賜教？", 50, 0);
    if AskBattle() == true then goto label1 end;
        Talk("喬幫主，不要誤會。這些日子以來，我總算看清楚了，誰是真英雄，誰是真小人。唉，可惜我做了太多錯事！蕭大哥，小弟今日愿與你并肩作戰，將功補過。不知你會不會嫌棄我？", 0, 0);
        Talk("如今我死在頃刻，情勢兇險，但你能不怕艱危挺身而出，足見還是個重義輕生的大丈夫、好漢子。好！自今日起，咱們既往不咎。", 50, 1);
        Talk("大哥果然胸襟寬廣。來吧！讓我們四個放手一搏！", 0, 0);
        Talk("幾個狂妄的小子，你們有勝算嗎？", 140, 1);
        Talk("鳩摩智！", 0, 0);
        if HaveItemBool(128) == true then goto label2 end;
            Talk("小子，你敢欺師滅祖啊！", 46, 1);
            Talk("少廢話丁老怪，受死吧！", 0, 0);
            if TryBattle(176) == true then goto label3 end;
                Dead();
                exit();
::label3::
                LightScence();
                if InTeam(51) == false then goto label4 end;
                    LeaveTeam(51);
::label4::
                    if InTeam(48) == false then goto label5 end;
                        LeaveTeam(48);
::label5::
                        Talk("哈哈！真痛快！阿紫，我們走。", 50, 0);
                        Talk("好！姐夫。", 130, 1);
                        Talk("阿紫姑娘，等等我……", 48, 0);
                        AddItem(128, 1);
                        Talk("總算把這東西也拿回來了。", 0, 0);
                        LeaveTeam(47);
                        ModifyEvent(-2, -2, -2, -2, 1213, -2, -2, -2, -2, -2, -2, -2, -2);
exit();
::label2::
                        Talk("今天老子弊了你。", 49, 1);
                        if TryBattle(176) == true then goto label6 end;
                            Dead();
                            exit();
::label6::
                            LightScence();
                            if InTeam(48) == false then goto label7 end;
                                LeaveTeam(48);
::label7::
                                if InTeam(51) == false then goto label8 end;
                                    LeaveTeam(51);
::label8::
                                    Talk("哈哈！真痛快！阿紫，我們走。", 50, 0);
                                    Talk("好！姐夫。", 130, 1);
                                    Talk("阿紫姑娘，等等我……", 48, 0);
                                    LeaveTeam(47);
                                    AddFame(20);
                                    ModifyEvent(-2, -2, -2, -2, 1213, -2, -2, -2, -2, -2, -2, -2, -2);
exit();
::label1::
                                    Talk("嘻嘻，我們應該不用比了吧。別忘了，你可是我的手下敗將。", 0, 0);
                                    Talk("我大哥和你往日無冤，近日無仇。公子何必呢？", 138, 1);
                                    Talk("雞掰人，想跟我打嗎？", 49, 0);
                                    Talk("小兄弟，今日你若幫我們制住了喬峰，不但為武林除了害，自己更會名傳天下，令群雄敬仰。", 139, 1);
                                    Talk("呵呵，好像還是慕容兄更有道理哦。", 0, 0);
                                    if TryBattle(177) == true then goto label9 end;
                                        Dead();
                                        exit();
::label9::
                                        LightScence();
                                        if InTeam(53) == false then goto label10 end;
                                            LeaveTeam(53);
::label10::
                                            if InTeam(49) == false then goto label11 end;
                                                LeaveTeam(49);
::label11::
                                                Talk("小兄弟，恭喜你啊！", 139, 0);
                                                Talk("慕容公子客氣了，大家彼此彼此。哈哈！", 0, 1);
                                                if HaveItemBool(128) == false then goto label12 end;
                                                    AddFame(20);
                                                    AddMorality(-20);
                                                    ModifyEvent(-2, -2, -2, -2, 1213, -2, -2, -2, -2, -2, -2, -2, -2);
                                                    exit();
::label12::
                                                    Talk("果然是我的好徒弟。今日你立次大功，我就把掌門之位傳給你。", 46, 0);
                                                    Talk("多謝師父！", 0, 1);
                                                    AddItem(128, 1);
                                                    AddFame(20);
                                                    AddMorality(-20);
                                                    ModifyEvent(-2, -2, -2, -2, 1213, -2, -2, -2, -2, -2, -2, -2, -2);
exit();
