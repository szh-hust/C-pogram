# C-pogram
made in 2021/5/4 

华中科技大学（湖北 武汉）人工智能与自动化学院（AIA）

C语言课程设计

平安好车主的模拟与主要功能实现

编译环境：Borland C++3.1

一些说明：

+ 本系统可以在 win2000/winxp/vista/win7/win10下完美使用 Borland C/C++ 3.1，包括图形程序。
  所有环境均已经配置好，不用修改。
  双击执行“Borland C++ 3.1”即可。

  win11系统是否兼容，没有尝试

+ 由于虚拟了 DOS 环境，文件夹 DISK_C 就是 C:\，使用文件路径的时候需要注意。
  例如，图形程序中初始化图形环境的代码：
  int gdriver=VGA, gmode=VGAHI;
  initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI");

+ 路径说明：
  dosbox		虚拟 DOS 环境的软件 DosBox 0.72
  DISK_C		虚拟的 DOS 环境的 C:\
    └BORLANDC	Borland C/C++ 3.1 程序文件

+ Alt + Enter 可以切换全屏/窗口。
