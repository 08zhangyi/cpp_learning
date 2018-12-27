#pragma once

class MailMessage
{};

class PostMasterMessage : public MailMessage
{
public:
	PostMasterMessage();
	PostMasterMessage(pAddress sender, pAddress recipient, pString subject, pDate, creationDate);

	~PostMasterMessage();
	pAddress& getSender() const;
	void setSender(pAddress&);

private:
	pAddress sender;
	pAddress recipient;
	pString subject;
	pDate creationDate;
	pDate lastModDate;
	pDate receiptDate;
	pDate firstReadDate;
	pDate lastReadDate;
};