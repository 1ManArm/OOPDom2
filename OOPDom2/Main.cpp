#include <iostream>
#include <vector>
#include <string>
//Компоновка класса, проблема робмовидного наследования

/*	Компоновка класса
Компоненты класса:
	-поля
	-методы
	-функционал родительского класса
	
Способы компоновки:
	-агрегация
		-включает поля, отсутствие которых не влечет последствий для работы класса
	-композиция
		-методы класса - всегда часть композиции
		-поля - в зависимости от того, как работает класс
	-наследование
		-объект наследник получает композиционно в себя объект родительского класса и наследует правила по компоновке его полей и методов
	
Ромбовидное наследование
	-ситуация, в которой несколько ветвей наследования базового класса приходят к одному общему наследнику

	Проблемы на поверхности
	-код с ромбовидным наследованием не гарантировано компилируется
	-необходимо переопределять методы во множественном наследнике

	*/

//Пример ромбовидного наследования
//class Base {
//public:
//	Base() = default;
//	Base(const std::string& name):name_(name){}
//	virtual ~Base() = default;
//	void setName(const std::string& name) {
//		name_ = name;
//	}
//private:
//	std::string name_;
//};
//
//class Item :virtual public Base {
//public:
//	Item() = default;
//	Item(const std::string& name, double weight) :Base(name), weight_(weight) {}
//	void setWeight(const double& value) {
//		weight_ = value;
//	}
//	double getWeight() const {
//		return weight_;
//	}
//private:
//	double weight_;
//};
//
//class Creature :virtual public Base {
//public:
//	Creature() = default;
//	Creature(const std::string& name, double &speed) :Base(name), speed_(speed) {}
//public:
//	void setSpeed(const double& value) {
//		speed_ = value;
//	}
//	double getSpeed() const {
//		return speed_;
//	}
//protected:
//	Creature(double& speed):speed_(speed){}
//private:
//	double &speed_;
//};
//
//class Robot : public Item, public Creature {
//	Robot() = default;
//	Robot(const std::string& name, double weight, double &speed) :Base(name), Creature(speed) {
//		setWeight(weight);
//	}
//};

class MechanismPart {
public:
	MechanismPart() = default;
	MechanismPart(const std::string& name) : name_(name) {}
	virtual ~MechanismPart() = default;
	void setName(const std::string& name) {
		name_ = name;
	}
private:
	std::string name_;
};
class Wheels : virtual public MechanismPart {
public:
	Wheels() = default;
	Wheels(const std::string& name, int& wquantity):MechanismPart(name), wquantity_(wquantity){}
	void setWquant(const int& value) {
		wquantity_ = value;
	}
protected:
	Wheels(int& wquantity):wquantity_(wquantity){}
private:
	int &wquantity_;
};

class Engine :virtual public MechanismPart {
public:
	Engine() = default;
	Engine(const std::string& name, std::string& engintype):MechanismPart(name), engintype_(engintype){}
	void setEngine(const std::string& value) {
		engintype_ = value;
	}
protected:
	Engine(std::string& engintype) :engintype_(engintype){}
private:
	std::string& engintype_;
};

class Body :virtual public MechanismPart {
public:
	Body() = default;
	Body(const std::string& name, std::string& bodytype):MechanismPart(name), bodytype_(bodytype){}
	void setBody(const std::string& value) {
		bodytype_ = value;
	}
protected:
	Body(std::string& bodytype): bodytype_(bodytype){}
private:
	std::string& bodytype_;
};

class Automobile :public Wheels, public Engine, public Body {
	Automobile() = default;
	Automobile(const std::string& name, int wquantity, std::string engintype, std::string bodytype) :MechanismPart(name), Wheels(wquantity), Engine(engintype), Body(bodytype) {}

};

int main() {
	setlocale(LC_ALL, "Russian");

	//Base a("object");
	//Item i("chair", 15.3);
	//Creature c("cat", 3.5);
	//Robot r{ "Wall-e", 40.1, 2.0 };
	//r.Item::setName("Wall-e");

	Automobile compact{ "Compact", 4, "I4", "Sedan" };

	return 0;
}