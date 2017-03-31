# Stickman
:runner:Create a stick man and let it move like a real man<br>
__________________________________________________________________________________________
Author:赵明福                                        Student ID：201400301087                            E-mail:1109646702@qq.com<br>
## Assignment
Last class,we have learn many knowledge about transformation.Now you need to complete the project II this week,I guess teacher has introduced the detail about this project,please create your stick man and let it move like a real man,I believe you can complete it perfectly.You can get the instruction from "No.5 Transformation" P63-82

If you have any issues about this project ,please send your issues before 3/24.TA's Email are:rey_cn@foxmail.com and 411648085@qq.com,Thanks

Remember there is a experimental lesson at 3/24 13:30-17:30 and 3/31 13:30-17:30<br>
    　　　　　　　　　　　   ![](https://github.com/Chicharito999/ImageCache/raw/master/image/stickman.gif)
## Analysis
思考人在走路或奔跑时的特征：
* 开始时，左右腿中一只腿先动，同时相反方向的胳膊开始向上摆动
* 随后，当先开始摆动的腿或胳膊往回摆时，另一对腿和胳膊开始向上摆动
* 胳膊在上摆动时，开始总是大小胳膊一起旋转，当旋转到一定角度时，大胳膊保持不动，小胳膊继续旋转一定的角度
* 胳膊在下摆动时与上面相反，小胳膊先向回旋转，随后大小胳膊一起复位
* 腿在摆动时，大腿旋转的角度远远大于小腿，尤其是在奔跑时小腿可以看作是一直垂直与地面
* 无论是胳膊还是腿向后旋转的角度并不大，可以考虑也可以忽略

glPushMatrix()、glPopMatrix()：<br>
由于小胳膊既会自己摆动也会和大胳膊一起摆动，所以要用层次的思想来解决，opengl提供了glPushMatrix()、glPopMatrix()函数用于层次化绘制glPushMatrix()的作用是把矩阵压入栈中保存起来，留着以后再用，就好象把子弹压入枪膛一样，同时栈顶复制一份被压入的矩阵。所以调用glPushMatrix()之后的操作相当于在上一层矩阵的基础之上进行的操作，同理上一层的矩阵操作对下一层也有效。glPopMatrix()函数可以将栈顶的矩阵移除，下一层成为当前层，相当于把弹夹中最上面的子弹发射出去，让下面那颗子弹成为弹夹最顶上那颗。所以，大、小胳膊摆动的问题可以用下面的方式来解决：<br> 
```cpp
glRotatef(i, -1, 0, 0);//控制上胳膊与下胳膊旋转i度  
glPushMatrix();//矩阵压栈并在栈顶复制一份
glTranslatef(0.0, -1, 0.0);//移动到右下胳膊处
glRotatef(ii, -1, 0, 0);//控制下胳膊旋转ii度 
drawSkewed(1, 1.5, 1, WIRE);//绘制右下胳膊
glPopMatrix();//栈顶矩阵出栈  回到大胳膊处
drawSkewed(1, 1.5, 1, WIRE);//绘制右上胳膊
glPopMatrix();//栈顶矩阵出栈  回到右肩膀处
