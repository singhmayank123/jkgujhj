#include <iostream>
#include <string>
#include <unordered_map>

// Function to parse XML-like attributes and store them in a map
std::unordered_map<std::string, std::string> parseAttributes(const std::string& xmlAttributes) {
    std::unordered_map<std::string, std::string> attributeMap;

    size_t pos = 0;
    while (pos < xmlAttributes.length()) {
        // Find the tag name
        size_t tagStart = xmlAttributes.find("<", pos);
        size_t tagEnd = xmlAttributes.find(" ", tagStart);
        if (tagEnd == std::string::npos) {
            tagEnd = xmlAttributes.find("/", tagStart);
        }

        if (tagStart != std::string::npos && tagEnd != std::string::npos) {
            std::string tagName = xmlAttributes.substr(tagStart + 1, tagEnd - tagStart - 1);

            // Find the attribute-value pairs
            size_t attrStart = tagEnd + 1;
            while (true) {
                size_t attrNameStart = xmlAttributes.find_first_not_of(" ", attrStart);
                if (attrNameStart == std::string::npos) {
                    break;
                }
                size_t attrNameEnd = xmlAttributes.find("=", attrNameStart);
                if (attrNameEnd == std::string::npos) {
                    break;
                }

                std::string attributeName = xmlAttributes.substr(attrNameStart, attrNameEnd - attrNameStart);

                size_t attrValueStart = xmlAttributes.find("\"", attrNameEnd) + 1;
                size_t attrValueEnd = xmlAttributes.find("\"", attrValueStart);
                std::string attributeValue = xmlAttributes.substr(attrValueStart, attrValueEnd - attrValueStart);

                attributeMap[attributeName] = attributeValue;

                attrStart = attrValueEnd + 1;
            }
        }

        // Move to the next tag
        pos = tagEnd + 1;
    }

    return attributeMap;
}

int main() {
    std::string xmlAttributes;
    std::cout << "Enter XML-like attributes: ";
    std::getline(std::cin, xmlAttributes);

    // Parse the attributes and store them in a map
    std::unordered_map<std::string, std::string> attributeMap = parseAttributes(xmlAttributes);

    // Query specific attributes
    std::string queryAttribute;
    while (true) {
        std::cout << "Enter the attribute name to query (or 'exit' to quit): ";
        std::getline(std::cin, queryAttribute);

        if (queryAttribute == "exit") {
            break;
        }

        auto it = attributeMap.find(queryAttribute);
        if (it != attributeMap.end()) {
            std::cout << "Attribute value for '" << queryAttribute << "': " << it->second << std::endl;
        } else {
            std::cout << "Attribute not found." << std::endl;
        }
    }

    return 0;
}

