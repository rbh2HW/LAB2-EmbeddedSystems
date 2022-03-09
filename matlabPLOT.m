%
close all;
task1.time=15;
task2.time=200;
task3.time=1000;
task4.time=41;
task5.time=41;
task6.time=100;
task7.time=333;
task8.time=333;
task9.time=5000;

task1arr=zeros(1,5000);
task2arr=zeros(1,5000);
task3arr=zeros(1,5000);
task4arr=zeros(1,5000);
task5arr=zeros(1,5000);
task6arr=zeros(1,5000);
task7arr=zeros(1,5000);
task8arr=zeros(1,5000);
task9arr=zeros(1,5000);

overallArray=strings(1,5000);
counter=1;

totalSlotTime=10;

onewait=totalSlotTime-2;
twowait=totalSlotTime-2;
threewait=totalSlotTime-3;
fourwait=totalSlotTime-10;
fivewait=totalSlotTime-1;
sixwait=totalSlotTime-2;
sevenwait=totalSlotTime-1;
eightwait=totalSlotTime-2;
ninewait=totalSlotTime-1;

lastCounter=counter;
for i=1:5000

    if mod(i,task1.time)==0
        task1arr(i)=1;
        overallArray(counter)="one,";
        counter=counter+1;
%         endwait=counter+onewait;
%         overallArray(counter:endwait)="burn,";
%         counter=counter+1;
    end
    if  mod(i,task2.time)==0
        task2arr(i)=1;
        overallArray(counter)="two,";
        counter=counter+1;
%         endwait=counter+twowait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task3.time)==0
        task3arr(i)=1;
        overallArray(counter)="three,";
        counter=counter+1;
%         endwait=counter+threewait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task4.time)==0
        task4arr(i)=1;
        overallArray(counter)="four,";
        counter=counter+1;
%         endwait=counter+fourwait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task5.time)==0
        task5arr(i)=1;
        overallArray(counter)="five,";
        counter=counter+1;
%         endwait=counter+fivewait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task6.time)==0
        task6arr(i)=1;
        overallArray(counter)="six,";
        counter=counter+1;
%         endwait=counter+sixwait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task7.time)==0
        task7arr(i)=1;
        overallArray(counter)="seven,";
        counter=counter+1;
%         endwait=counter+sevenwait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task8.time)==0
        task8arr(i)=1;
        overallArray(counter)="eight,";
        counter=counter+1;
%         endwait=counter+eightwait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if  mod(i,task9.time)==0
        task9arr(i)=1;
        overallArray(counter)="nine,";
        counter=counter+1;
%         endwait=counter+ninewait;
%         overallArray(counter:endwait)="burn,";
%         counter=endwait+1;
    end
    if (lastCounter ==counter)
        overallArray(counter)="burn,";
        counter=counter+1;

    end

    lastCounter=counter;

end

overallArray=overallArray';

plot(task1arr)
hold on
plot(task2arr)
hold on
plot(task3arr)
hold on
plot(task4arr)
hold on
plot(task5arr)
hold on
plot(task6arr)
hold on
plot(task7arr)
hold on
plot(task8arr)
hold on
plot(task9arr)
hold on

figure(2)


subplot(3,3,1)
plot(task1arr)
title('task1')

subplot(3,3,2)
plot(task2arr)
title('task2')

subplot(3,3,3)
plot(task3arr)
title('task3')

subplot(3,3,4)
plot(task4arr)
title('task4')

subplot(3,3,5)
plot(task5arr)
title('task5')

subplot(3,3,6)
plot(task6arr)
title('task6')

subplot(3,3,7)
plot(task7arr)
title('task7')

subplot(3,3,8)
plot(task8arr)
title('task8')

subplot(3,3,9)
plot(task9arr)
title('task9')