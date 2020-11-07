#include "mgaemailform.h"
#include "ui_mgaemailform.h"

MGAEmailForm::MGAEmailForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MGAEmailForm)
{
    ui->setupUi(this);
}

MGAEmailForm::~MGAEmailForm()
{
    delete ui;
}

bool MGAEmailForm::SendEmail()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and password
        // for smtp authentification.

        smtp.setUser("amirtossonsiegen@gmail.com");
        smtp.setPassword("");

        // Now we create a MimeMessage object. This is the email.

        MimeMessage message;

        EmailAddress sender("amirtossonsiegen@gmail.com", "Tosson");
        message.setSender(&sender);

        EmailAddress to("amirsamytosson@hotmail.com", "Recipient's Name");
        message.addRecipient(&to);

        message.setSubject("SmtpClient for Qt - Demo");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText("Hi,\nThis is a simple email message.\n");

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        if (!smtp.connectToHost()) {
            qDebug() << "Failed to connect to host!" << endl;
            return -1;
        }

        if (!smtp.login()) {
            qDebug() << "Failed to login!" << endl;
            return -2;
        }

        if (!smtp.sendMail(message)) {
            qDebug() << "Failed to send mail!" << endl;
            return -3;
        }

        smtp.quit();
}
