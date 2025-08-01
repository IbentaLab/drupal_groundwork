
# Personalized Welcome Component

This component displays a personalized welcome message to users.

## Component Settings

This is a presentational component. Its only responsibility is to display the data (or settings) it is given. It contains no dynamic logic itself.

* **`welcome_message`** : The main heading text.
* **`last_login`** : A sub-heading for the user's last login date.
* **`generic_content`** : A general content area.

## Dynamic Functionality (Important)

All dynamic functionality, such as fetching the current user's name and last login date, is handled by the **'Personalized Welcome' block** provided by the **Groundwork Helpers Components** module.

### How it Works

1. The **'Personalized Welcome' block** automatically detects if a user is logged in.
2. Based on the user's status, it generates the correct welcome message and formats the last login date.
3. It then sends this information to the visual component to be displayed.

### Using in a Twig Template

If you place this component directly in a Twig template using `{{ include() }}`, you are using the visual template without the block's dynamic logic. In this case, you **must** provide all the content manually.

Below are examples of how to provide this static data for testing or direct rendering.

#### Logged-in User Example

```
{{ include('groundwork:welcome', {
  welcome_message: 'Welcome back, Jane Doe!',
  last_login: 'You last logged in on July 31, 2025 at 7:02 PM.',
  generic_content: '<p>Here are some quick links to get you started. We have updated our terms of service, please review them at your earliest convenience.</p>'
}, with_context = false) }}

```

#### Anonymous Guest Example

```
{{ include('groundwork:welcome', {
  welcome_message: 'Welcome, guest!',
  last_login: '',
  generic_content: '<p>Sign up today to receive exclusive offers, save your favorite articles, and join our community. It only takes a minute!</p>'
}, with_context = false) }}

```
