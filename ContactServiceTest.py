import unittest
from Contact import Contact
from ContactService import ContactService


class ContactServiceTest(unittest.TestCase):
    # unit test for adding contact
    def test_add(self):
        cs = ContactService()
        test1 = Contact("1413252", "Jane", "Doe", "4444444444", "22 Jump Drive")
        self.assertTrue(cs.add_contact(test1))

    # unit test for deleting contact
    def test_delete(self):
        cs = ContactService()

        test1 = Contact("1234567", "Jane", "Doe", "4444444444", "22 Jump Drive")
        test2 = Contact("7943196", "Alan", "Turing", "8752064285", "Roses Valley")
        test3 = Contact("5507859", "Erwin", "Schrodinger", "9215501793", "Land of Disney")

        cs.add_contact(test1)
        cs.add_contact(test2)
        cs.add_contact(test3)

        self.assertTrue(cs.delete_contact("1234567"))
        self.assertFalse(cs.delete_contact("1309404"))
        self.assertFalse(cs.delete_contact("1309403"))

    # unit test for updating contact
    def test_update(self):
        cs = ContactService()

        test1 = Contact("1234567", "Jane", "Doe", "4444444444", "22 Jump Drive")
        test2 = Contact("7943196", "Alan", "Turing", "8752064285", "Roses Valley")
        test3 = Contact("5507859", "Erwin", "Schrodinger", "9215501793", "Land of Disney")

        cs.add_contact(test1)
        cs.add_contact(test2)
        cs.add_contact(test3)

        self.assertTrue(cs.update_contact("5507859", "ErwinFirst", "SchrodingerLast", "9215501793", "Land of Disney"))
        self.assertFalse(cs.update_contact("9752322", "ErwinFirst", "SchrodingerLast", "9215501793", "Land of Disney"))
