Talk("就是這個石碑吧，看老子一全打暴他。", 0, 0);
DarkScence();
ModifyEvent(-2, 0, 0, -2, -1, -1, -1, -1, -1, -1, -2, -2, -2);
LightScence();
Talk("兄弟且慢，我們都來這里跟你道別。", 162, 1);
Talk("兄弟，你真的要走了？", 1, 1);
Talk("是啊，胡大哥。謝謝你對兄弟這些日子的照顧和幫助。", 0, 0);
Talk("哪的話。要是沒有兄弟你，我的大仇也無法得報。唉……真有點舍不得你啊！", 1, 1);
Talk("大哥，天下無不散之宴席。", 0, 0);
Talk("也對。這樣吧，兄弟。咱們是打架認識的，今天大哥最后再陪你打一架。不知你一下如何？", 1, 1);
Talk("大哥有此興致，小弟自當奉陪。好！就讓我們放開手腳，好好再打一架。", 0, 0);
SetRoleMagic(1, 0, 67, 900);
SetRoleMagic(2, 0, 1, 900);
if TryBattle(164) == true then goto label0 end;
    LightScence();
exit();
::label0::
    LightScence();
    Talk("痛快，真痛快！", 1, 0);
    Talk("鐵丑，我們也送送小哥吧。", 130, 1);
    Talk("是，阿紫姑娘。", 48, 0);
    SetRoleMagic(47, 0, 78, 900);
    SetRoleMagic(47, 1, 27, 900);
    if TryBattle(165) == true then goto label1 end;
        LightScence();
exit();
::label1::
        LightScence();
        Talk("真可惜，你也要走了。以后又少了一個人陪我玩了。", 130, 0);
        Talk("不會啊，你還有鐵面陪你。", 0, 1);
        Talk("對啊，我永遠不會離開阿紫姑娘的。", 48, 0);
        Talk("我們說話你少插嘴。", 130, 1);
        Talk("是，是。", 48, 0);
        Talk("哈哈，鐵面。以后恐怕還有的你受得呢！", 0, 1);
        Talk("大哥，我林平之家仇得報全虧了你。今日，我們夫婦也要送你一程。", 36, 0);
        SetRoleMagic(36, 0, 60, 900);
        if TryBattle(166) == true then goto label2 end;
            LightScence();
exit();
::label2::
            LightScence();
            Talk("林兄弟，記得要好好照顧你娘子，知道嗎？", 0, 0);
            Talk("知道，我會的。", 36, 1);
            Talk("小兄弟，這些丹要你也許會用的到，我送給你。", 28, 0);
            AddItem(1, 10);
            Talk("多謝平大夫了！", 0, 1);
            Talk("酒逢知己千杯少，兄弟和盈盈敬你。", 35, 0);
            Talk("好，干。", 0, 1);
            Talk("狀哉！來兄弟，我也來送你一程。", 35, 0);
            Talk("你們怎么能忘了我？也算我一個。", 25, 1);
            Talk("好，大家一起來！", 0, 0);
            SetRoleMagic(35, 5, 61, 900);
            SetRoleMagic(35, 6, 28, 900);
            if TryBattle(167) == true then goto label3 end;
                LightScence();
exit();
::label3::
                LightScence();
                Talk("兄弟，終于輪到我了。我和敏敏芷若小昭都來送你。", 9, 0);
                Talk("好兄弟，不必多說了。讓我領教領教你的九陽神功和周姑娘的九陰白骨爪。", 0, 1);
                SetRoleMagic(9, 1, 48, 900);
                SetRoleMagic(9, 2, 88, 900);
                if TryBattle(168) == true then goto label4 end;
                    LightScence();
exit();
::label4::
                    LightScence();
                    Talk("九陰九陽，孰弱孰強？陰陽交合，天下稱王！哈哈哈……", 0, 0);
                    Talk("大哥，你知道兄弟我不喜歡動武，但今日大家以武送友，小弟也不好壞了規矩。我也來獻獻丑，大家點到為止。", 138, 1);
                    Talk("來兄弟。正好請王姑娘指教指教。", 0, 0);
                    Talk("不敢，少俠請。", 109, 1);
                    SetRoleMagic(53, 1, 29, 900);
                    if TryBattle(169) == true then goto label5 end;
                        LightScence();
exit();
::label5::
                        LightScence();
                        Talk("少俠，老夫沒有別的好東西，這些丹藥略表存心。", 45, 0);
                        AddItem(16, 10);
                        Talk("薛神醫太客氣了！", 0, 1);
                        Talk("小哥，我大哥、大嫂本已隱居，但聽說你要走也特來相送。", 136, 0);
                        Talk("這怎么敢當？多謝楊大哥，楊大嫂！", 0, 1);
                        Talk("是我們該向你道謝，沒有你我們也不會重逢。", 121, 0);
                        Talk("來吧，兄弟。今日一戰，也不枉我們相交一場。", 118, 1);
                        if TryBattle(170) == true then goto label6 end;
                            LightScence();
exit();
::label6::
                            LightScence();
                            Talk("小兄弟，我們幾條光棍也來送送你，愿你一路走好！", 37, 0);
                            Talk("謝謝幾位大哥，請！", 0, 1);
                            if TryBattle(171) == true then goto label7 end;
                                LightScence();
exit();
::label7::
                                LightScence();
                                Talk("小兄弟，他們都是大俠好漢，我們幾個雖不是好人，但知道你要走還得來送。總不能叫人家說我們只有江湖，沒有道義。", 29, 0);
                                Talk("我交朋友不分貴賤，但求交心。幾位來吧！", 0, 1);
                                if TryBattle(172) == true then goto label8 end;
                                    LightScence();
exit();
::label8::
                                    LightScence();
                                    Talk("兄弟來了就知道了。", 137, 0);
                                    Talk("江南七怪一言九鼎，豈能言而無信?", 0, 0);
                                    Talk("還有一些財寶，不拿白不拿。", 137, 0);
                                    Talk("大哥!", 0, 0);
                                    SetRoleMagic(56, 4, 87, 900);
                                    if TryBattle(213) == true then goto label9 end;
                                        LightScence();
                                        exit();
::label9::
                                        LightScence();
                                        Talk("唉，你們年輕人就是胡鬧。少俠費了不少力氣吧。", 16, 0);
                                        Talk("胡大夫，你活過來了?", 0, 1);
                                        Talk("我詐死躲仇家不行嗎?來，把這個拿上。", 16, 0);
                                        AddItem(9, 10);
                                        Talk("阿碧姑娘，再麻煩你帶我進入燕子塢了．", 0, 0);
                                        if TryBattle(192) == true then goto label10 end;
                                            LightScence();
                                            Talk("痛快!各位兄弟姐妹，小弟我要走了。各位請多保重！青山不改，綠水長流。我們后會有期！", 0, 0);
                                            exit();
::label10::
                                            LightScence();
                                            Talk("痛快!各位兄弟姐妹，小弟我要走了。各位請多保重！青山不改，綠水長流。我們后會有期！", 0, 1);
exit();
