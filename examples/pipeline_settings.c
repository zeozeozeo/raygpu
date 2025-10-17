#include <raygpu.h>

DescribedSampler sampler;
Shader depthless;
RenderTexture multisampled_rt;

void setup(){
    sampler = LoadSampler(TEXTURE_WRAP_REPEAT, TEXTURE_FILTER_BILINEAR);
    depthless = LoadShader(NULL, NULL);
    multisampled_rt = LoadRenderTextureEx(640, 720, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8, 4, 1);
    SetShaderSampler(depthless, 2, sampler);
    
}
void render(){
    BeginDrawing();
        ClearBackground(BLANK);

        BeginTextureMode(multisampled_rt);
        ClearBackground(BLANK);
        BeginShaderMode(depthless);
        
        DrawCircle(GetMouseX(), GetMouseY(), 50.0f, WHITE);
        DrawTriangle(
            (Vector2){GetMousePosition().x, GetMousePosition().y + 100}, 
            (Vector2){GetMousePosition().x - 30, GetMousePosition().y + 300}, 
            (Vector2){GetMousePosition().x + 30, GetMousePosition().y + 300}, 
            GREEN
        );
        EndShaderMode();
        EndTextureMode();


        DrawCircle(GetMouseX(), GetMouseY(), 50.0f, WHITE);
        DrawTriangle(
            (Vector2){GetMousePosition().x, GetMousePosition().y + 100}, 
            (Vector2){GetMousePosition().x - 30, GetMousePosition().y + 300}, 
            (Vector2){GetMousePosition().x + 30, GetMousePosition().y + 300}, 
            GREEN
        );
        DrawTexture(multisampled_rt.texture, 0, 0, WHITE);
        DrawRectangle(638, 0, 4, 720, RED);
        DrawText("MSAA On", 5, 5, 30, GREEN);
        DrawText("MSAA Off", 645, 5, 30, GREEN);
        DrawFPS(5, 70);
    EndDrawing();
}
int main(void){
    ProgramInfo info = {
        .windowTitle = "Multisampled Rendertexture Example",
        .windowWidth = 1280,
        .windowHeight = 720,
        .setupFunction = setup,
        .renderFunction = render,
    };
    InitProgram(info);
}
