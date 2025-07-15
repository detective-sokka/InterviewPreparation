/*
Problem:
You're building a notification system that can send notifications via Email, SMS, or Push. 
The client code should not worry about the creation logic of the notification type.

Goal:
Implement a factory that returns the appropriate Notification object based on user input or configuration.
*/

/*
Entities - 
class Notification
class EmailNotification inherits Notification
class SMS inherits inherits Notification
class Push inherits inherits Notification

class NotificationFactory
class EmailNotificationFactory inherits NotificationFactory
class SMSNotificationFactory inherits NotificationFactory
class PushNotificationFactory inherits NotificationFactory

NotificationFactory is associated with Notification <<creates>> 
*/

#include <iostream>
#include <memory>

class Notification
{
    public: 
        virtual void sendNotification() = 0;
};

class EmailNotification : public Notification
{
    public:
        void sendNotification() override
        {
            std::cout << "\nEmail Notification sent.";
        }
};

class SMSNotification : public Notification
{
    public:
        void sendNotification() override
        {
            std::cout << "\nSMS Notification sent.";
        }
};

class PushNotification : public Notification
{
    public:
        void sendNotification() override
        {
            std::cout << "\nPush Notification sent.";
        }
};

class NotificationFactory
{
    public: 
        virtual std::shared_ptr<Notification> createNotification() = 0;
};

class EmailNotificationFactory : public NotificationFactory
{
    public: 
        std::shared_ptr<Notification> createNotification() override
        {
            return std::make_shared<EmailNotification>(EmailNotification{});
        }
};

class SMSNotificationFactory : public NotificationFactory
{
    public: 
        std::shared_ptr<Notification> createNotification() override
        {
            return std::make_shared<SMSNotification>(SMSNotification{});
        }
};

class PushNotificationFactory : public NotificationFactory
{
    public:
        std::shared_ptr<Notification> createNotification() override
        {
            return std::make_shared<PushNotification>(PushNotification{});
        }
};

int main()
{
    return 0;
}