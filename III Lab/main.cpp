#include "Resources.h"
#include "Model.h"
#include "Render.h"
#include "Controller.h"

int main()
{
    Resources::Instance().Load();
    Model game;
    Render render(&game);
    Controller controller(&game, &render);
    controller.Run();
    return 0;
}
