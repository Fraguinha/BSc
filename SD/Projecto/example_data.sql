-- Example books
INSERT INTO "APP".BOOK ("NAME", "AUTHOR", "PUBLISHER", "LANGUAGE", "GENRE", "YEAR_PUBLICATION", "QUANTITY", "PRICE")
VALUES ('Book 1', 'Author 1', 'Publisher 1', 'PT', 'Fiction', 2012, 2, 4.99);

INSERT INTO "APP".BOOK ("NAME", "AUTHOR", "PUBLISHER", "LANGUAGE", "GENRE", "YEAR_PUBLICATION", "QUANTITY", "PRICE")
VALUES ('Book 2', 'Author 1', 'Publisher 2', 'PT', 'Fiction', 2014, 3, 9.99);

INSERT INTO "APP".BOOK ("NAME", "AUTHOR", "PUBLISHER", "LANGUAGE", "GENRE", "YEAR_PUBLICATION", "QUANTITY", "PRICE")
VALUES ('Book 3', 'Author 2', 'Publisher 3', 'EN', 'Non Fiction', 2017, 6, 24.99);

INSERT INTO "APP".BOOK ("NAME", "AUTHOR", "PUBLISHER", "LANGUAGE", "GENRE", "YEAR_PUBLICATION", "QUANTITY", "PRICE")
VALUES ('Book 4', 'Author 3', 'Publisher 4', 'EN', 'Fiction', 2020, 6, 14.99);

INSERT INTO "APP".BOOK ("NAME", "AUTHOR", "PUBLISHER", "LANGUAGE", "GENRE", "YEAR_PUBLICATION", "QUANTITY", "PRICE")
VALUES ('Book 5', 'Author 3', 'Publisher 4', 'EN', 'Fiction', 2021, 10, 14.99);

-- Example user
INSERT INTO "APP".USERS ("EMAIL", "USERNAME", "PASSWORD", "TYPE")
VALUES ('example@email.com', 'admin', 'admin', 0);

INSERT INTO "APP".USERS ("EMAIL", "USERNAME", "PASSWORD", "TYPE")
VALUES ('example@email.com', 'user', 'user', 1);
