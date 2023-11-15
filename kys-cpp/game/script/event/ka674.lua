Talk("林師父，每次聞到你的菜都想留下來住個幾天，好好的　大吃一頓．無奈任務還未完成，沒有時間也沒有心情．", 0, 1);
Talk("那就等你空閑時再來吧．我一定為你準備一頓豐盛的大餐．", 75, 0);
if isUsingItem(138) == true then goto label0 end;
    if isUsingItem(139) == true then goto label1 end;
        if isUsingItem(140) == true then goto label2 end;
            if isUsingItem(141) == true then goto label3 end;
                if isUsingItem(142) == true then goto label4 end;
exit();
::label4::
                    Talk("好東西啊！", 75, 1);
                    Talk("林師傅，這東西你要不要？", 0, 0);
                    Talk("啊呀，這是做菜的好材料，謝謝你啊！對了，這顆開竅丹送你，你吃了吧。", 75, 1);
                    AddItemWithoutHint(142, -1);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 0);
                    Talk("不客氣，有空常來。", 75, 1);
exit();
::label3::
                    Talk("好東西啊！", 75, 1);
                    Talk("林師傅，這東西你要不要？", 0, 0);
                    Talk("啊呀，這是做菜的好材料，謝謝你啊！對了，這顆開竅丹送你，你吃了吧。", 75, 1);
                    AddItemWithoutHint(141, -1);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 0);
                    Talk("不客氣，有空常來。", 75, 1);
exit();
::label2::
                    Talk("好東西啊！", 75, 1);
                    Talk("林師傅，這東西你要不要？", 0, 0);
                    Talk("啊呀，這是做菜的好材料，謝謝你啊！對了，這顆開竅丹送你，你吃了吧。", 75, 1);
                    AddItemWithoutHint(140, -1);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 0);
                    Talk("不客氣，有空常來。", 75, 1);
exit();
::label1::
                    Talk("好東西啊！", 75, 1);
                    Talk("林師傅，這東西你要不要？", 0, 0);
                    Talk("啊呀，這是做菜的好材料，謝謝你啊！對了，這顆開竅丹送你，你吃了吧。", 75, 1);
                    AddItemWithoutHint(139, -1);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 0);
                    Talk("不客氣，有空常來。", 75, 1);
exit();
::label0::
                    Talk("好東西啊！", 75, 1);
                    Talk("林師傅，這東西你要不要？", 0, 0);
                    Talk("啊呀，這是做菜的好材料，謝謝你啊！對了，這顆開竅丹送你，你吃了吧。", 75, 1);
                    AddItemWithoutHint(138, -1);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 0);
                    Talk("不客氣，有空常來。", 75, 1);
exit();
