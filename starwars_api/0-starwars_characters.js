#!/usr/bin/env node
const request = require('request');

const movieId = process.argv[2];

if (!movieId) {
  console.error('Usage: Need a movie ID');
  console.exit(1);
}

const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

request(url, (error, response, body) => {
  if (error) {
    console.error(error);
  }
  const data = JSON.parse(body);
  const characters = data.characters;

  printCharacterName(characters, 0);
});

function printCharacterName(characters, index) {
  if (index >= characters.length) {
    return;
  }
  request(characters[index], (error, response, body) => {
    if (error) {
      console.error(error);
    }
    const characterdata = JSON.parse(body);
    const name = characterdata.name;
    console.log(name);

    printCharacterName(characters, index + 1);
  });
}
