#include <iostream>
using namespace std;

class Light{
public:
    void on(){ cout << "�}�O" << endl; }
    void off(){ cout << "���O" << endl; }
};
class Door{
public:
    void open(){ cout << "�}��" << endl; }
    void close(){ cout << "����" << endl; }
};

class Command{
public:
    virtual void execute() = 0;
};
class NoCommand: public Command{
public:
    void execute(){ cout << "�|���j�w�R�O" << endl; }
};
class LightOnCommand: public Command{
private:
    Light *m_light;
public:
    LightOnCommand(Light *light){ m_light = light; }
    void execute(){ m_light->on(); }
};
class LightOffCommand: public Command{
private:
    Light *m_light;
public:
    LightOffCommand(Light *light){ m_light = light; }
    void execute(){ m_light->off(); }
};
class DoorOpenCommand: public Command{
private:
    Door *m_door;
public:
    DoorOpenCommand(Door *door){ m_door = door; }
    void execute(){ m_door->open(); }
};
class DoorCloseCommand: public Command{
private:
    Door *m_door;
public:
    DoorCloseCommand(Door *door){ m_door = door; }
    void execute(){ m_door->close(); }
};

class RemoteControl{
private:
    Command *m_onCommands[3];
    Command *m_offCommands[3];
public:
    RemoteControl(Command *);
    void setCommand(int slot, Command *on, Command *off);
    void pressOnButton(int slot){ m_onCommands[slot]->execute(); }
    void pressOffButton(int slot){ m_offCommands[slot]->execute(); }
};
RemoteControl::RemoteControl(Command *command){
    for (int i = 0; i < 3; i++){
        m_onCommands[i] = command;
        m_offCommands[i] = command;
    }
}
void RemoteControl::setCommand(int slot, Command *on, Command *off){
    m_onCommands[slot] = on;
    m_offCommands[slot] = off;
}

int main(){
    Light myLight;
    Door myDoor;
    LightOnCommand command1(&myLight);
    LightOffCommand command2(&myLight);
    DoorOpenCommand command3(&myDoor);
    DoorCloseCommand command4(&myDoor);

    NoCommand nocommand;
    RemoteControl myControl(&nocommand);
    myControl.setCommand(0, &command1, &command2);
    myControl.setCommand(1, &command3, &command4);
    for (int i = 0; i < 3; i++){
        myControl.pressOnButton(i);
        myControl.pressOffButton(i);
    }
    system("PAUSE");
    return 0;
}