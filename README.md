# JSON-Parser
C++ JSON Parser

# ONION ARCHITECTURE 
# UI -> Controllers -> Services -> Repository
# UI ->
	open
	close
	saveas <file> [<path>]
	print
    user input
# Controllers ->
	calls for services by given params (UI commands) 
	pattern matching for UI commands (could be another layer)
# Services ->
	set <path> <string>	
	create <path> <string>
	delete <path>
	move <from> <to>
# Validator -> 
	validate user input
	response from services (exceptions) 
# Repository -> 
	file system 
# Business Objects ->
	content of JSON file
	
