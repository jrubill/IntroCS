# for caching the page
import os.path
import sys
# for webscraping
from bs4 import BeautifulSoup
import requests

class Scraper:

	# constructor for Scraper object
	def __init__(self):
		self.page = None
		self.soup = None
	
	def getHTML(self, url):
		'''
		I'm caching the page so we don't keep hitting the site 
		'''
		if os.path.exists('cache.html'):
			with open('cache.html', 'r') as f:
				data = f.read()
			self.page = data
		else:
			data = requests.get(url).text
			with open('cache.html', 'w') as f:
				f.write(data)
			if self.page is None:
				self.page = data
		return data

	def setSoup(self):
		if self.page is None:
			print("Error: page not set!")
		else:
			self.soup = BeautifulSoup(self.page, 'html.parser')

	def getArticles(self):
		if self.soup is None:
			print("Error: no soup set!")
		else:
			data = self.soup.find_all('article', class_='product_pod')
			return data

if __name__ == "__main__":
	scraper = Scraper()
	
	scraper.getHTML('http://books.toscrape.com')
	scraper.setSoup()

	# This should get all the articles in the page
	books = scraper.getArticles()

	if books is None:
		print("No books found! :(")
		sys.exit(0)
	

	# iterate through all the books and find the cheapest one
	lowest = None
	for book in books:
		if lowest is None:
			lowest = [ book.find('h3').a['title'], book.find('p', class_='price_color').text[2:] ]
		elif book.find('p', class_='price_color').text[2:] < lowest[1]:
			lowest = [ book.find('h3').a['title'], book.find('p', class_='price_color').text[2:] ]
	
	print(lowest[0])
