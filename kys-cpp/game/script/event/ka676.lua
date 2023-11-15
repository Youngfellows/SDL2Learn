CheckHave5Item(138, 139, 140, 141, 142, 148, 0);
if isUsingItem(138) == true then goto label0 end;
    if isUsingItem(139) == true then goto label1 end;
        if isUsingItem(140) == true then goto label2 end;
            if isUsingItem(141) == true then goto label3 end;
                if isUsingItem(142) == true then goto label4 end;
exit();
::label4::
                    AddItemWithoutHint(142, -1);
                    Talk("嘿，好東西啊！這可是做菜的好材料。", 75, 0);
                    Talk("那我送給你好了。給，林師傅。", 0, 1);
                    Talk("這粒開竅豆我送給你吃，當作報答吧。", 75, 0);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 1);
exit();
::label3::
                    AddItemWithoutHint(141, -1);
                    Talk("嘿，好東西啊！這可是做菜的好材料。", 75, 0);
                    Talk("那我送給你好了。給，林師傅。", 0, 1);
                    Talk("這粒開竅豆我送給你吃，當作報答吧。", 75, 0);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 1);
exit();
::label2::
                    AddItemWithoutHint(140, -1);
                    Talk("嘿，好東西啊！這可是做菜的好材料。", 75, 0);
                    Talk("那我送給你好了。給，林師傅。", 0, 1);
                    Talk("這粒開竅豆我送給你吃，當作報答吧。", 75, 0);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 1);
exit();
::label1::
                    AddItemWithoutHint(139, -1);
                    Talk("嘿，好東西啊！這可是做菜的好材料。", 75, 0);
                    Talk("那我送給你好了。給，林師傅。", 0, 1);
                    Talk("這粒開竅豆我送給你吃，當作報答吧。", 75, 0);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 1);
exit();
::label0::
                    Talk("嘿，好東西啊！這可是做菜的好材料。", 75, 0);
                    Talk("那我送給你好了。給，林師傅。", 0, 1);
                    Talk("這粒開竅豆我送給你吃，當作報答吧。", 75, 0);
                    AddIQ(0, 2);
                    Talk("這東西真棒，頭腦現在特別清醒。謝謝啦！", 0, 1);
exit();
exit();
