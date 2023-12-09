class Contact:
    def __init__(self, contactID, firstName, lastName, phoneNumber, address):
        self.contactID = contactID
        self.firstName = firstName
        self.lastName = lastName
        self.phoneNumber = phoneNumber
        self.address = address

    # getter and setter for contact id
    def get_contact_id(self):
        return self.contactID

    def set_contact_id(self, contactID):
        self.contactID = contactID

    # getter and setter for first name
    def get_first_name(self):
        return self.firstName

    def set_first_name(self, firstName):
        self.firstName = firstName

    # getter and setter for last name
    def get_last_name(self):
        return self.lastName

    def set_last_name(self, lastName):
        self.lastName = lastName

    # getter and setter for phone number
    def get_phone_number(self):
        return self.phoneNumber

    def set_phone_number(self, phoneNumber):
        self.phoneNumber = phoneNumber

    # getter and setter for address
    def get_address(self):
        return self.address

    def set_address(self, address):
        self.address = address

    # returns the contact info in a string
    def __str__(self):
        return (f"Contact [contactID= {self.contactID}, firstName= {self.firstName}, lastName= {self.lastName}"
                f", phoneNumber= {self.phoneNumber}, address= {self.address}]")
