#include<iostream>
#include<string>
using namespace std;

// Abstract base class for employee behavior
class IEmployee {
public:
    virtual void professional() = 0;
};

// Abstract base class for family member behavior
class IFamilyMember {
public:
    virtual void casualBehaviour() = 0;
    virtual void cranky() = 0;
};

// Person class implementing both IEmployee and IFamilyMember interfaces
class Person : public IEmployee, public IFamilyMember {
public:
    void casualBehaviour() override {
        cout << "Casual behavior: Watching TV." << endl;
    }
    void professional() override {
        cout << "Professional behavior: Attending meetings." << endl;
    }
    void cranky() override {
        cout << "Cranky behavior: Complaining about the weather." << endl;
    }
};

// Context class for office environment
class OfficeContext {
public:
    void enter(IEmployee* obj) {
        obj->professional();
    }
};

// Context class for family environment
class FamilyContext {
public:
    void enter(IFamilyMember* obj) {
        obj->cranky();
        obj->casualBehaviour();
    }
};

int main() {
    // Create a Person object
    Person tom;

    // Initialize contexts
    FamilyContext fContext;
    OfficeContext oContext;

    // Enter family context and office context for Tom
    cout << "Tom's family behavior:" << endl;
    fContext.enter(&tom);
    cout << endl;

    cout << "Tom's office behavior:" << endl;
    oContext.enter(&tom);
    cout << endl;

    // Create another Person object
    Person harry;

    // Enter family context and office context for Harry
    cout << "Harry's family behavior:" << endl;
    fContext.enter(&harry);
    cout << endl;

    cout << "Harry's office behavior:" << endl;
    oContext.enter(&harry);
    cout << endl;

    return 0;
}
