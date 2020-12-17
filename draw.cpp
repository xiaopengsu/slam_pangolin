//
////example1: Task1：创建一个简单的Pangolin   创建一个交互窗口，并在窗口中显示一个立方体和对应的坐标系
////  https://blog.csdn.net/weixin_43991178/article/details/105119610
//#include <pangolin/pangolin.h> /*引入pangolin的头文件，Pangolin几乎所有的功能都在该头文件中。*/
//
//int main( int /*argc*/, char** /*argv*/ )
//{
//    // 创建名称为“Main”的GUI窗口，尺寸为640×640
//    pangolin::CreateWindowAndBind("Main",640,480); /*函数的入口的参数依次为视窗的名称、宽度和高度*/
//    // 启动深度测试
//    glEnable(GL_DEPTH_TEST); /*启动了深度测试功能，该功能会使得pangolin只会绘制朝向镜头的那一面像素点，避免容易混淆的透视关系出现，因此在任何3D可视化中都应该开启该功能。*/
//
//    // 创建一个观察相机视图
//    pangolin::OpenGlRenderState s_cam(                                   //      参数依次为观察相机的图像高度、宽度、4个内参以及最近和最远视距
//            pangolin::ProjectionMatrix(640,480,420,420,320,320,0.2,100), /*ProjectMatrix(int h, int w, int fu, int fv, int cu, int cv, int znear, int zfar)*/
//            pangolin::ModelViewLookAt(2,0,2, 0,0,0, pangolin::AxisY)/*ModelViewLookAt(double x, double y, double z,double lx, double ly, double lz, AxisDirection Up)*/
//    );   //参数依次为相机所在的位置，以及相机所看的视点位置(一般会设置在原点)
//
//    // 创建交互视图-
//    pangolin::Handler3D handler(s_cam); //交互相机视图句柄
//    pangolin::View& d_cam = pangolin::CreateDisplay() /*创建一个交互式视图（view）用于显示上一步摄像机所“拍摄”到的内容*/
//            .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f/480.0f)/*setBounds()函数前四个参数依次表示视图在视窗中的范围（下、上、左、右），可以采用相对坐标（0~1）以及绝对坐标（使用Attach对象）。*/
//            .SetHandler(&handler);
//
//    while( !pangolin::ShouldQuit() )
//    {
//        // 清空颜色和深度缓存
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        d_cam.Activate(s_cam);/*使用glclear命令分别清空色彩缓存和深度缓存并激活之前设定好的视窗对象（否则视窗内会保留上一帧的图形，这种“多重曝光”效果通常并不是我们需要的）。*/
////
////        // 在原点绘制一个立方体
////        pangolin::glDrawColouredCube();
//        // 绘制坐标系
//        glLineWidth(3);
//        glBegin ( GL_LINES );
//        glColor3f ( 0.8f,0.f,0.f );
//        glVertex3f( -1,-1,-1 );
//        glVertex3f( 0,-1,-1 );
//        glColor3f( 0.f,0.8f,0.f);
//        glVertex3f( -1,-1,-1 );
//        glVertex3f( -1,0,-1 );
//        glColor3f( 0.2f,0.2f,1.f);
//        glVertex3f( -1,-1,-1 );
//        glVertex3f( -1,-1,0 );
//        glEnd();
//
//        // 运行帧循环以推进窗口事件
//        pangolin::FinishFrame(); /*用FinishFrame命令刷新视窗*/
//    }
//
//    return 0;
//}




//
////example1: Task2：将Task1中的代码改写为多线程版本： //todo
//
//#include <pangolin/pangolin.h>
//#include <thread>
//
//static const std::string window_name = "HelloPangolinThreads";
//
//void setup() {
//    // create a window and bind its context to the main thread
//    pangolin::CreateWindowAndBind(window_name, 640, 480);
//
//    // enable depth
//    glEnable(GL_DEPTH_TEST);
//
//    // unset the current context from the main thread
//    pangolin::GetBoundWindow()->RemoveCurrent();  //todo bug /*https://github.com/stevenlovegrove/Pangolin/pull/398*/
//}
//
//void run() {
//    // fetch the context and bind it to this thread
//    pangolin::BindToContext(window_name);
//
//    // we manually need to restore the properties of the context
//    glEnable(GL_DEPTH_TEST);
//
//    // Define Projection and initial ModelView matrix
//    pangolin::OpenGlRenderState s_cam(
//            pangolin::ProjectionMatrix(640,480,420,420,320,240,0.2,100),
//            pangolin::ModelViewLookAt(-2,2,-2, 0,0,0, pangolin::AxisY)
//    );
//
//    // Create Interactive View in window
//    pangolin::Handler3D handler(s_cam);
//    pangolin::View& d_cam = pangolin::CreateDisplay()
//            .SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f/480.0f)
//            .SetHandler(&handler);
//
//    while( !pangolin::ShouldQuit() )
//    {
//        // Clear screen and activate view to render into
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        d_cam.Activate(s_cam);
//
//        // Render OpenGL Cube
//        pangolin::glDrawColouredCube();
//
//        // Swap frames and Process Events
//        pangolin::FinishFrame();
//    }
//
//    // unset the current context from the main thread
//    pangolin::GetBoundWindow()->RemoveCurrent(); //todo bug
//}
//
//int main( int /*argc*/, char** /*argv*/ )
//{
//    // create window and context in the main thread
//    setup();
//
//    // use the context in a separate rendering thread
//    std::thread render_loop;
//    render_loop = std::thread(run);
//    render_loop.join();
//
//    return 0;
//}

//
//
////example2: Task3：为Pangolin添加控件
//#include <pangolin/pangolin.h>
//#include <string>
//#include <iostream>
//// ----------------------------------------------------------------- //
//
//void SampleMethod()
//{
//    std::cout << "You typed ctrl-r or pushed reset" << std::endl;
//    // std::cout << "Window width: " << i << std::endl;
//}
//// ----------------------------------------------------------------------- //
//int main(/*int argc, char* argv[]*/)
//{
//
//    // 创建视窗
//    pangolin::CreateWindowAndBind("Main",640,480);
//    // 启动深度测试
//    glEnable(GL_DEPTH_TEST);
//    // 创建一个摄像机
//    pangolin::OpenGlRenderState s_cam(
//            pangolin::ProjectionMatrix(640,480,420,420,320,240,0.1,1000),
//            pangolin::ModelViewLookAt(-0,0.5,-3, 0,0,0, pangolin::AxisY)
//    );
//    // 分割视窗
//    const int UI_WIDTH = 180;
//
//    // 右侧用于显示视口
//    pangolin::View& d_cam = pangolin::CreateDisplay()
//            .SetBounds(0.0, 1.0, pangolin::Attach::Pix(UI_WIDTH), 1.0, -640.0f/480.0f)
//            .SetHandler(new pangolin::Handler3D(s_cam));
//    // 左侧用于创建控制面板
//    pangolin::CreatePanel("ui")
//            .SetBounds(0.0, 1.0, 0.0, pangolin::Attach::Pix(UI_WIDTH));
//
//    // 创建控制面板的控件对象，pangolin中
//    pangolin::Var<bool> A_Button("ui.a_button", false, false);  // 按钮
//    pangolin::Var<bool> A_Checkbox("ui.a_checkbox", false, true); // 选框
//    pangolin::Var<bool> B_Checkbox("ui.b_checkbox", false, false); // 选框
//    pangolin::Var<double> Double_Slider("ui.a_slider", 3, 0, 5); //double滑条
//    pangolin::Var<int> Int_Slider("ui.b_slider", 2, 0, 5); //int滑条
//    pangolin::Var<std::string> A_string("ui.a_string", "Hello Pangolin");
//
//    pangolin::Var<bool> SAVE_IMG("ui.save_img", false, false);  // 按钮
//    pangolin::Var<bool> SAVE_WIN("ui.save_win", false, false); // 按钮
//    pangolin::Var<bool> RECORD_WIN("ui.record_win", false, false); // 按钮
//
//    pangolin::Var<std::function<void()>> reset("ui.Reset", SampleMethod);//
//
//    // 绑定键盘快捷键
//    // Demonstration of how we can register a keyboard hook to alter a Var
//    pangolin::RegisterKeyPressCallback(pangolin::PANGO_CTRL + 'b', pangolin::SetVarFunctor<double>("ui.a_slider", 3.5));
//
//    // Demonstration of how we can register a keyboard hook to trigger a method
//    pangolin::RegisterKeyPressCallback(pangolin::PANGO_CTRL + 'r', SampleMethod);
//    // Default hooks for exiting (Esc) and fullscreen (tab).
//    while( !pangolin::ShouldQuit() )
//    {
//        // Clear entire screen
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // 各控件的回调函数
//        if(pangolin::Pushed(A_Button))
//            std::cout << "Push button A." << std::endl;
//
//        if(A_Checkbox)
//            Int_Slider = Double_Slider;
//        // 保存整个win
//        if( pangolin::Pushed(SAVE_WIN) )
//            pangolin::SaveWindowOnRender("window");
//        // 保存view
//        if( pangolin::Pushed(SAVE_IMG) )
//            d_cam.SaveOnRender("cube");
//        // 录像
//        if( pangolin::Pushed(RECORD_WIN) )
//            pangolin::DisplayBase().RecordOnRender("ffmpeg:[fps=50,bps=8388608,unique_filename]//screencap.avi");
//        d_cam.Activate(s_cam);
//        // glColor3f(1.0,0.0,1.0);
//        pangolin::glDrawColouredCube();
//
//        // Swap frames and Process Events
//        pangolin::FinishFrame();
//    }
//
//    return 0;
//}



//
//
////example3:Task 4：多视图与图片显示  https://blog.csdn.net/weixin_43991178/article/details/105142470
//
//#include <opencv2/opencv.hpp>
//#include <pangolin/pangolin.h>
//
//int main(int argc, char** argv){
//    // 创建视窗
//    pangolin::CreateWindowAndBind("MultiImage", 752, 480);
//    // 启动深度测试
//    glEnable(GL_DEPTH_TEST);
//    // 设置摄像机
//    pangolin::OpenGlRenderState s_cam(
//            pangolin::ProjectionMatrix(752, 480, 420, 420, 320, 320, 0.1, 1000),
//            pangolin::ModelViewLookAt(-2, 0, -2, 0, 0, 0, pangolin::AxisY)
//    );
//    // ---------- 创建三个视图 ---------- //
//    pangolin::View& d_cam = pangolin::Display("cam")
//            .SetBounds(0., 1., 0., 1., -752/480.)
//            .SetHandler(new pangolin::Handler3D(s_cam));
//
//    pangolin::View& cv_img_1 = pangolin::Display("image_1")
//            .SetBounds(2/3.0f, 1.0f, 0., 1/3.0f, 752/480.)
//            .SetLock(pangolin::LockLeft, pangolin::LockTop);
//
//    pangolin::View& cv_img_2 = pangolin::Display("image_2")
//            .SetBounds(0., 1/3.0f, 2/3.0f, 1.0, 752/480.)
//            .SetLock(pangolin::LockRight, pangolin::LockBottom);
//    // 创建glTexture容器用于读取图像
//    pangolin::GlTexture imgTexture1(752, 480, GL_RGB, false, 0, GL_BGR, GL_UNSIGNED_BYTE);
//    pangolin::GlTexture imgTexture2(752, 480, GL_RGB, false, 0, GL_BGR, GL_UNSIGNED_BYTE);
//
//    while(!pangolin::ShouldQuit()){
//        // 清空颜色和深度缓存
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        // 启动相机
//        d_cam.Activate(s_cam);
//        // 添加一个立方体
//        glColor3f(1.0f, 1.0f, 1.0f);
//        pangolin::glDrawColouredCube();
//        // 从文件读取图像
//        cv::Mat img1 = cv::imread("../data/1.png"); /*在视窗左上角和右下角实时显示了EuRoc数据集中的图像*/
//        cv::Mat img2 = cv::imread("../data/2.png");
//        // 向GPU装载图像
//        imgTexture1.Upload(img1.data, GL_BGR, GL_UNSIGNED_BYTE);
//        imgTexture2.Upload(img2.data, GL_BGR, GL_UNSIGNED_BYTE);
//        // 显示图像
//        cv_img_1.Activate();
//        glColor3f(1.0f, 1.0f, 1.0f); // 设置默认背景色，对于显示图片来说，不设置也没关系
//        imgTexture1.RenderToViewportFlipY(); // 需要反转Y轴，否则输出是倒着的
//
//        cv_img_2.Activate();
//        glColor3f(1.0f, 1.0f, 1.0f); // 设置默认背景色，对于显示图片来说，不设置也没关系
//        imgTexture2.RenderToViewportFlipY();
//
//        pangolin::FinishFrame();
//    }
//
//    return 0;
//}



//example5: 使用Pangolin画出相机的轨迹

#include <iostream>
#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <sophus/se3.h>
using namespace std;

typedef vector<Sophus::SE3, Eigen::aligned_allocator<Sophus::SE3>> VecSE3;
typedef vector<Eigen::Vector3d, Eigen::aligned_allocator<Eigen::Vector3d>> VecVec3d;

string file = "../data/KeyFrameTrajectory.txt";

void Draw(const VecSE3 &poses);
int main(int argc, char **argv)
{
    //读位姿
    VecSE3 poses;
    VecVec3d points;
    ifstream fin(file);//位姿

    string lineStr;
    int j = 0;
    while(getline(fin,lineStr))//每行
    {
        j+=1;//隔100个点取一个数据
        if (j%10 != 0 )
            continue;

        //cout<<lineStr <<endl;
        stringstream ss(lineStr);
        string str;
        double data[8];
        int i = 0;
        while (getline(ss, str, ' '))
        {
            stringstream intg(str);
            if (i >= 8)//只取前八个
                continue;
            intg >> data[i];
            i+=1;
        }
        poses.push_back(Sophus::SE3(
                //eigen.tuxfamily.org/dox-devel/classEigen_1_1Quaternion.html
                Eigen::Quaterniond(data[4], data[5], data[6], data[7]),//四元数
                Eigen::Vector3d(data[1], data[2], data[3])//位移
        ));
        //cout << data[1] <<" "<< data[2]<<" "<< data[3]<<" "<< data[4]<<endl;//位移
        if (!fin.good()) break;

    }
    fin.close();

    Draw(poses);
    return 0;

}

void Draw(const VecSE3 &poses)
{
    if (poses.empty() )
    {
        cerr << "parameter is empty!" << endl;
        return;
    }
    // create pangolin window and plot the trajectory
    pangolin::CreateWindowAndBind("Trajectory Viewer", 1024, 768);
    glEnable(GL_DEPTH_TEST);//深度测试 gl--> opengl--> OpenGL
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    pangolin::OpenGlRenderState s_cam(//摆放一个相机
            pangolin::ProjectionMatrix(1024, 768, 500, 500, 512, 389, 0.1, 1000),
            pangolin::ModelViewLookAt(0, -0.1, -1.8, 0, 0, 0, 0.0, -1.0, 0.0)
    );
    pangolin::View &d_cam = pangolin::CreateDisplay()//创建一个窗口
            .SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -1024.0f / 768.0f)
            .SetHandler(new pangolin::Handler3D(s_cam));

    while (pangolin::ShouldQuit() == false)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//消除颜色缓冲
        d_cam.Activate(s_cam);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        // draw poses
        //画相机朝向
        for (auto &Twc: poses)//从poses中取位姿
        {
            glPushMatrix();
            Sophus::Matrix4f m = Twc.matrix().cast<float>();
            glMultMatrixf((GLfloat *) m.data());

            const float w = 0.25;
            const float h = w*0.75;
            const float z = w*0.6;
            glColor3f(1, 0, 0);
            glLineWidth(2);
            glBegin(GL_LINES);
            //画相机模型
            glVertex3f(0, 0, 0);
            glVertex3f(w,h,z);
            glVertex3f(0, 0, 0);
            glVertex3f(w,-h,z);
            glVertex3f(0, 0, 0);
            glVertex3f(-w,-h,z);
            glVertex3f(0, 0, 0);
            glVertex3f(-w,h,z);
            glVertex3f(w,h,z);
            glVertex3f(w,-h,z);
            glVertex3f(-w,h,z);
            glVertex3f(-w,-h,z);
            glVertex3f(-w,h,z);
            glVertex3f(w,h,z);
            glVertex3f(-w,-h,z);
            glVertex3f(w,-h,z);

            glEnd();
            glPopMatrix();
        }

        //画轨迹
        glLineWidth(2);
        for (size_t i = 0; i < poses.size() - 1; i++)
        {
            glColor3f(1 - (float) i / poses.size(), 0.0f, (float) i / poses.size());
            glBegin(GL_LINES);
            auto p1 = poses[i], p2 = poses[i + 1];
            glVertex3d(p1.translation()[0], p1.translation()[1], p1.translation()[2]);
            glVertex3d(p2.translation()[0], p2.translation()[1], p2.translation()[2]);
        }
        glEnd();
        pangolin::FinishFrame();
        usleep(5000);   // sleep 5 ms
    }
}