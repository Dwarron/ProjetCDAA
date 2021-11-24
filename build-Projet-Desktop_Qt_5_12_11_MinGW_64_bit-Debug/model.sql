--
-- Fichier généré par SQLiteStudio v3.3.3 sur mer. nov. 24 22:49:25 2021
--
-- Encodage texte utilisé : System
--
PRAGMA foreign_keys = off;
--BEGIN TRANSACTION;

-- Table : Contact
CREATE TABLE IF NOT EXISTS Contact (Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, nom STRING NOT NULL, prenom STRING NOT NULL, entreprise STRING, telephone VARCHAR (10), mail STRING, uriPhoto STRING, dateCreation VARCHAR (10) NOT NULL, dateModification VARCHAR (10) NOT NULL);

-- Table : ContactsToInteractions
CREATE TABLE IF NOT EXISTS ContactsToInteractions (ContactId INTEGER REFERENCES Contact (Id), InteractionId INTEGER REFERENCES Interaction (Id));

-- Table : Infos
CREATE TABLE IF NOT EXISTS Infos (dateDerniereSuppression STRING NOT NULL DEFAULT "01/01/2021");

-- Table : Interaction
CREATE TABLE IF NOT EXISTS Interaction (Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, date VARCHAR (10) NOT NULL, resume STRING NOT NULL);

-- Table : Todo
CREATE TABLE IF NOT EXISTS Todo (Id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, InteractionId INTEGER REFERENCES Interaction (Id) NOT NULL, echeance VARCHAR (10) NOT NULL DEFAULT "01/01/2021", contenu STRING NOT NULL DEFAULT "", effectue BOOLEAN NOT NULL DEFAULT (0));

--COMMIT TRANSACTION;
PRAGMA foreign_keys = on;