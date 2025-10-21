#include <raygpu.h>

void mainloop(){
    BeginDrawing();
    ClearBackground(DARKBLUE);
    //DrawRectangle(100,100,100,100,RED);
    //drawCurrentBatch();
    //rlScalef(100, 0, 0);
    rlPushMatrix();
    rlTranslatef(200,0,0);
    DrawRectangle(200,200,200,200,GREEN);
    rlPopMatrix();
    EndDrawing();
}
void setup(){

}

int main(){
    ProgramInfo prog = {
        .windowWidth = 800,
        .windowHeight = 600,
        .setupFunction = setup,
        .renderFunction = mainloop,
    };
    InitProgram(prog);
}
