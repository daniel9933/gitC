#include <string>
#include <iostream>
#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->_id = id;
	this->_username = username;
	this->_age = age;
	this->_devices.init();
}
void User::clear()
{
	this->_devices.clear();
}
unsigned int User::getID() const
{
	return this->_id;
}
std::string User::getUserName() const
{
	return this->_username;
}
unsigned int User::getAge() const
{
	return this->_age;
}
DevicesList& User::getDevices() const
{
	return this->_devices.
}
void User::addDevice(Device newDevice)
{
	this->_devices.add(newDevice);
}
bool User::checkIfDevicesAreOn() const
{
	DeviceNode* device = this->_devices.get_first();

	for (; device != nullptr; device = device->get_next())
	{
		if (device->get_data().isActive() == false)
		{
			return false;
		}
	}
	return true;
}