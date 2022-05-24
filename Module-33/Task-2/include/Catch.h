#pragma once

class Catch {
public:
	virtual ~Catch() {}
	virtual void get() = 0;
};

class Fish :public Catch {
public:
	void get() override { throw* this; }
};

class Boot :public Catch {
	void get() override { throw* this; };
};