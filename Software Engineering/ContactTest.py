import unittest
from Contact import Contact


class ContactTest(unittest.TestCase):
    # unit test for length of contact ID
    def test_contact_id_length(self):
        contact = Contact("12345678900", "FirstName", "LastName", "PhoneNumbr", "Address")
        self.assertLessEqual(len(contact.contactID), 10, "Contact ID has more than 10 characters.")

    # unit test for length of first name
    def test_contact_first_name_length(self):
        contact = Contact("ContactID", "OllyOllyOxenFree", "LastName", "PhoneNumbr", "Address")
        self.assertLessEqual(len(contact.firstName), 10, "First Name has more than 10 characters.")

    # unit test for length of last name
    def test_contact_last_name_length(self):
        contact = Contact("ContactID", "FirstName", "OllyOllyOxenFree", "PhoneNumbr", "Address")
        self.assertLessEqual(len(contact.lastName), 10, "Last Name has more than 10 characters.")

    # unit test for length of phone number
    def test_contact_phone_length(self):
        contact = Contact("ContactID", "FirstName", "LastName", "5555555555", "Address")
        self.assertEqual(len(contact.phoneNumber), 10, "Phone number length does not equal 10.")

    # unit test for length of address
    def test_contact_address_length(self):
        contact = Contact("value is", "LastName", "FirstName", "PhoneNumbr", "address is longer than 30 characters")
        self.assertLessEqual(len(contact.address), 30, "Address is more than 30 characters.")

    # unit test for null first name
    def test_contact_first_name_not_null(self):
        contact = Contact("ContactID", "Test", None, None, None)
        self.assertIsNotNone(contact.firstName, "First name was null.")

    # unit test for null last name
    def test_contact_last_name_not_null(self):
        contact = Contact("ContactID", None, "Test", None, None)
        self.assertIsNotNone(contact.lastName, "Last name was null.")

    # unit test for null phone number
    def test_contact_phone_not_null(self):
        contact = Contact("ContactID", None, None, "Test", None)
        self.assertIsNotNone(contact.phoneNumber, "Phone number was null.")

    # unit test for null address
    def test_contact_address_not_null(self):
        contact = Contact("ContactID", None, None, None, "Test")
        self.assertIsNotNone(contact.address, "Address was null.")
