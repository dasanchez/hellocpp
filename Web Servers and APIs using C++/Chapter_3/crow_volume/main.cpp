#include "crow_all.h"
using namespace std;
using namespace crow;

int main(int argc, char* argv[]) {
    SimpleApp app;

    CROW_ROUTE(app, "/") ([](const request &req, response &res){
        ifstream in("../public/index.html", ifstream::in);
        cout << "INSIDE CROW ROUTE" << endl;
        if(in) {
            ostringstream contents;
            contents << in.rdbuf();
            in.close();
            res.write(contents.str());
        } else {
            res.write("FILE NOT FOUND!");
        }
        res.end();
    });

    char* port = getenv("PORT");
    uint16_t iPort = static_cast<uint16_t>(port != NULL ? stoi(port) : 18080);
    cout << "PORT = " << iPort << "\n";
    app.port(iPort).multithreaded().run();
}