class ContactService:
    def __init__(self):
        self.contacts = []

    # adds a contact by checking and then appending it to the list
    def add_contact(self, contact):
        contact_already = False
        for contact_list in self.contacts:
            if contact_list == contact:
                contact_already = True
                break

        if not contact_already:
            self.contacts.append(contact)
            return True
        else:
            return False

    # deletes all contacts that have the contactID
    def delete_contact(self, contactID):
        for contact_list in self.contacts:
            if contact_list.contactID == contactID:
                self.contacts.remove(contact_list)
                return True
        return False

    # updates contact information and verifies that info is usable
    def update_contact(self, contactID, firstName, lastName, phoneNumber, address):
        for contact_list in self.contacts:
            if contact_list.contactID == contactID:
                if firstName and len(firstName) <= 10:
                    contact_list.firstName = firstName
                if lastName and len(lastName) <= 10:
                    contact_list.lastName = lastName
                if phoneNumber and len(phoneNumber) == 10:
                    contact_list.phoneNumber = phoneNumber
                if address and len(address) <= 30:
                    contact_list.address = address
                return True
        return False
