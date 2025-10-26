#include <raygpu.h>

void mainloop(){
    BeginDrawing();
    ClearBackground(DARKBLUE);
    DrawRectangle(100,100,100,100,RED);
    drawCurrentBatch();
    
    rlPushMatrix();
    rlTranslatef(200,0,0);
    rlScalef(1.0f + 0.001f * (float)GetMouseX(),1,1);
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
