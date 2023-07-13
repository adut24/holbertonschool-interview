#!/usr/bin/node
const request = require('request');

/**
 * Get the name of the character
 * @param {String} character_url url of the character in the API
 */
function getName(character_url) {
  return new Promise((resolve, reject) => {
    request.get(character_url, (error, response, body) => {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

const displayData = async () => {
  try {
    const filmId = process.argv[2];
    request.get(`https://swapi-api.hbtn.io/api/films/${filmId}`, async (error, response, body) => {
      if (error) {
        console.log('Found error');
      } else {
        const names = await Promise.all(JSON.parse(body).characters.map(character => getName(character)));
        names.forEach(name => console.log(name));
      }
    });
  } catch (err) {
    console.log('Found error');
  }
};

displayData();
