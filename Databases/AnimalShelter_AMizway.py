#!/usr/bin/env python
# coding: utf-8

# In[2]:
##################################################################
############### Alex Mizway / CS-499 / Databases #################
##################################################################

import mysql.connector


class AnimalShelterMySQL(object):
    """ CRUD operations for Animal table in MySQL """

    def __init__(self):
        self.connection = mysql.connector.connect(
            user='root',
            password='root',
            host='127.0.0.1',
            database='AAC'
        )
        self.cursor = self.connection.cursor()

    def create(self, data):
        if data:
            columns = ', '.join(data.keys())
            values = ', '.join(['%s'] * len(data))
            query = f"INSERT INTO aac ({columns}) VALUES ({values})"
            self.cursor.execute(query, list(data.values()))
            self.connection.commit()
            return True
        else:
            raise Exception("Nothing to save, because data parameter is empty")

    def read(self, search_criteria=None):
        if search_criteria:
            conditions = ' AND '.join([f"{key} = '{value}'" for key, value in search_criteria.items()])
            query = f"SELECT * FROM aac WHERE {conditions}"
        else:
            query = "SELECT * FROM aac"
        self.cursor.execute(query)
        return self.cursor.fetchall()

    def update(self, data, new_values):
        if data:
            conditions = ' AND '.join([f"{key} = '{value}'" for key, value in data.items()])
            update_values = ', '.join([f"{key} = '{value}'" for key, value in new_values.items()])
            query = f"UPDATE aac SET {update_values} WHERE {conditions}"
            self.cursor.execute(query)
            self.connection.commit()
            return True
        else:
            print("Does not exist")

    def delete(self, data):
        if data:
            conditions = ' AND '.join([f"{key} = '{value}'" for key, value in data.items()])
            query = f"DELETE FROM aac WHERE {conditions}"
            self.cursor.execute(query)
            self.connection.commit()
            print("Deleting")
        else:
            print("Nothing to delete")

# In[ ]:

# %%
